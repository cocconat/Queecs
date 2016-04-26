# Queecs
Qualitative Estimator for Entropy and Correlation in String

#Brief therorical introduction to string compression
Through Information theory it s demonstrable [1][2] that bzip is a optimal compressor whose compression ratio tend to 
the entropy rate defined by Shannon.
the idea is then verify the structure of the string we re going to analyze:
any sequence (except for bernoullian sequence) has an internal structure which can be modellized as a markovian chain,
then inside it there are some sequence which can be predicted (in a probability meaning), for repetition
or for any internal rule we re not (directly) interested to.
Decomposing the sequence in to many blocks and mixing it we will destroy this rules and the compression will be harder,
since a structured text will be much more forecastable, then compressable, then another with same symbols in a different
position.
Queecs recreate a qualitative curve which express how long and how strong theese correlations are.

#how to run Queecs

```

make
./queecs file.xxx samples token

```

-samples is how many statistical samples you want to run
-token is a identifier for the data file you re creating

Your results are stored in *results* folder as curve_*token*.dat

#details
the blocks mixer program is written in C++
the process is execute in bash with a foor loop over a list of block dimensions.

I presented this work as my bachelor thesis, and I m happy in make it reusable, if you re interested mail to me.

#Thank you

Cocconat
