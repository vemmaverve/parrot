#! perl
# Copyright (C) 2011, Parrot Foundation.

use strict;
use warnings;
use lib qw( . lib ../lib ../../lib );
use Test::More;
use Parrot::Test tests => 1;
use Data::Dumper;

=head1 NAME

t/m0/m0bgen.t - M0 bytecode parser tests

=head1 SYNOPSIS

    % prove t/m0/m0bgen.t

=head1 DESCRIPTION

Test the M0 bytecode interpreter by generating simple known-good hard-coded M0
bytecode files.

Note that although this code behaves superficially like an assembler, it is not
and never will be an assembler.  Its only purpose is to generate superficially
valid M0 bytecode for testing, not to generate non-trivial runnable code.

=cut


my $M0_DIR_SEG      = 0x01;
my $M0_VARS_SEG     = 0x02;
my $M0_META_SEG     = 0x03;
my $M0_BC_SEG       = 0x04;


# basic test with one chunk containing all empty segments

my $m0_interp = '';

my $m0b_data = [
    { 
      name     => 'chunk_0',
      vars     => [],
      metadata => [],
      bytecode => [],
    },
    { 
      name     => 'chunk_1',
      vars     => [],
      metadata => [],
      bytecode => [],
    },
    { 
      name     => 'chunk_2',
      vars     => [],
      metadata => [],
      bytecode => [],
    },
];

m0b_build_file($m0b_data, "test.m0b");



=item C<m0b_build_file>

Generate an M0 bytecode file from m0b_data.

=cut

sub m0b_build_file {
    my ($chunks, $filename) = @_;

    my $bytes = m0b_build_bytes($chunks);
    open my $fh, '>', $filename or die "Couldn't open '$filename': $?";
    print $fh  $bytes;
    close $fh;

}


=item C<m0b_build_bytes>

Generate the binary version of an M0 chunk directory segment.

=cut

sub m0b_build_bytes {
    my ($chunks) = @_;
    
    #m0b magic number
    my $m0b_header = "asdfasdf";
    #intval size, floatval size, opcode_t size, void* size, endianness
    $m0b_header .= pack('CCCCCxxx', 4, 8, 4, 4, 0);

    my $m0b_bytes = $m0b_header;
    $m0b_bytes .= m0b_dir_seg( $chunks );

    for (@$chunks) {
        my $vars = $_{vars};
        my $meta_seg = m0b_meta_seg( $_{metadata}, $vars );
        my $vars_seg = m0b_vars_seg( $vars );
        my $bc_seg   = m0b_bc_seg(   $_{bytecode} );
        my $offset   = length($m0b_bytes);
        $m0b_bytes .= $vars_seg . $meta_seg . $bc_seg;
        #TODO: insert offset of vars segment into dir segment
    }

    return $m0b_bytes;
}


=item C<m0b_dir_seg>

Generate a directory for 

=cut

sub m0b_dir_seg {
    my ($chunks) = @_;

    my $dir_bytes = '';

    for (@$chunks) {
        #add 4 null bytes as a placeholder for the offset of the vars segment
        $dir_bytes .= pack('xxxx');
        $dir_bytes .= pack('L', length($_->{name}));
        $dir_bytes .= $_->{name};
    }

    my $seg_bytes =  pack('L', $M0_DIR_SEG);
    $seg_bytes    .= pack('L', length($dir_bytes));
    $seg_bytes    .= $dir_bytes;
    return $seg_bytes;
}


=item C<m0b_bc_seg>

Generate the binary version of an M0 bytecode segment, using "\0" for the bytes.

=cut

sub m0b_bc_seg {
    my ($size) = @_;

    my $bytecode_bytes = '';

    $bytecode_bytes = pack('CCCC', 0, 0, 0, 0);

    my $seg_bytes =  pack('L', $M0_BC_SEG);
    $seg_bytes    .= pack('L', length($bytecode_bytes));
    $seg_bytes    .= $bytecode_bytes;
    return $seg_bytes;
}

=item C<m0b_vars_seg>

Generate the binary version of an M0 variables segment, using the variables in
the first argument.

NOTE: Currently this generates an empty variables segment.  

=cut

sub m0b_vars_seg {
    my ($vars) = @_;

    my $vars_bytes = '';

    #TODO: actually populate variables segment
    #for each variable
      #write a 4-byte value of the size of the data
      #write the data

    my $seg_bytes =  pack("L", $M0_VARS_SEG);
    $seg_bytes    .= pack("L", length($vars_bytes));
    $seg_bytes    .= $vars_bytes;
    return $seg_bytes;
}

=item C<m0b_meta_seg>

Generate the binary version of an M0 metadata segment, using the values in the
first argument and adding them to the variables list in the second.

NOTE: Currently generates an empty metadata segment.

=cut

sub m0b_meta_seg {
    my ($metadata, $var_seg) = @_;
    
    my $metadata_bytes = '';

    #TODO: actually populate metadata segment
    #for each entry
        #get the index of the key
        #get the index of the value
        #append the offset, key and value to $metadata_bytes
        #increase size by 12

    my $seg_bytes =  pack("L", $M0_META_SEG);
    $seg_bytes    .= pack("L", length($metadata_bytes));
    $seg_bytes    .= $metadata_bytes;
    return $seg_bytes;
}


=item C<m0b_get_val_idx>

If the value exists in @$seg, return the index of it.  Otherwise, append it and
return the index.

=cut

sub m0b_get_val_idx {
    my ($val, $seg) = @_;

    my $val_idx = -1;
    for (my $i = 0; $i < scalar(@$seg); $i++) {
        return $i if ($seg->[$i] eq $val);
    }
    return push(@$seg, $val)-1;
}

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4: