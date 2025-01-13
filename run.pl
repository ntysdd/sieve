#!/usr/bin/perl
use v5.30;
use warnings;

use File::Spec::Functions qw(catfile);

my $val = $ARGV[0];
$val += 0;

my $exe = catfile( '.', 'sieve' );

for ( my $s = 10 ; $s <= 1000 ; $s += 2 ) {
    my @t = `$exe $s`;
    for my $o (@t) {
        if ( $o =~ m{^C $val (?<out>\d+)$} ) {
            my $v = $+{out};
            print "$s $v\n";
            last;
        }
    }
}
