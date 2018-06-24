#!/usr/bin/perl

#print @ARGV;

$_ = do { local $/; <> };

#s/any\(\)/\./g;
#s/R\(any\)/\./g;

s/\)\)\;/\)/g;

s/\)(\s*)B\(/\1\|/g;
s/X\(/\(/g;
s/B\(/\(/g;
s/NC\(\'\)\'\)/!'\CLOSEPAREN'/g;
s/NC\((.*?)\)/!\1/g;
s/C\(\'\)\'\)/'\CLOSEPAREN'/g;
s/C\((.*?)\)/\1/g;
s/R\((.*?)\)/\1/g;
s/RULE\((.*?),/\/\/\1 /g;
s/;//g;

s/(\s+)\((\s+)/\1\2/g;
s/(\s+)\)(\s+)/\1\2/g;

s/CLOSEPAREN/\)/g;

print;
