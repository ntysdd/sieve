#!/usr/bin/perl
use v5.10;
use warnings;
use strict;

my $s = 100000;


for (my $i = 10; $i <= $s; $i += 2)
{
    my $r = f($i);
    print "$i $r\n";
}

sub is_prime
{
    my $x = shift;
    if ($x <= 1)
    {
        return 0;
    }

    for (my $i = 2; $i * $i <= $x; $i++)
    {
        if ($x % $i == 0)
        {
            return 0;
        }
    }

    return 1;
}

sub f
{
    my $n = shift;
    my $sqrt = int(sqrt($n));

    my $r = 0.5 * $n;

    for (my $i = 3; $i <= $sqrt; $i++)
    {
        if (is_prime($i))
        {
            $r *= 1 - 2 / $i;
        }
    }

    return $r;
}
