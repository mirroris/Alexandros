# Roman_to_Arabian
This is a Scheme for transition from a Roman numeral to Arabian one.
ローマ数字をアラビア数字に翻訳します。

# How to use Alex?
./Alex {Roman Numeral}   is the way to translate Roman Numerals.
If you put numbers except Roman ones, the output inform you of that which charactor may be wrong.
example)

$ ./Alex IV
$ 4

If you don't give any argments, then you can execute interactive mode, which litterally enable you to talk with Alex! 

# How to ?
Actually, I use BNF below. Following the BNF rules, Alex understand the Roman numeral's structures.

What next you should do is translation! This is called translation scheme. 

I adopted the way using translation-tree generated from BNF syntax.

# Syntax For Roma numeral
I define like this:

sigma = {I,V,X,L,C,D,M}

**S**(initial) -> **S3** **S2** **S1** **S0**

**S3** -> M**S3'** | epsilon 

**S3'** -> M**S3''** | epsilon

**S3''** -> M | epsilon

as the same, but note that less than number of four digits have more complicated rules such as 4 or 9. 

**S2** -> CM | CD | D**SS2** | **SS2**

**SS2** -> C**SS2'** | epsilon 

**SS2'** -> C**SS2''** | epsilon

**SS2''** -> C | epsilon

as the same rule against less than 3 digits. 

example:replace C to X and D to L and M to C !!,then you'll get a rule for 2 digits.

Rejected Procedure:
**S3** -> M | M**S3'** | epsilon
**S3'** -> M | MM | epsilon
(or
**S3'** -> M | M**S3''** | epsilon
**S3''** -> M | epsilon
)
