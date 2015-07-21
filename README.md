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
It s pretty easy and soon it will have a make file.
in  the while just compile it:

g++ -o mixer.o cpp_mixer.cpp -std=c++11
bash bblock_mixer.sh moby.txt 20 mobydick
gnuplot -e 'plot "curve_mobydick.dat" u 1:2:3 w e'

moby dick is a trial text. 
bash bbloc_mixer.sh --help give some info

#technical dettails
the blocks mixer program is written in C++
the process is execute in bash trough many repetitions (Samples ~40).

I presented this work as my bachelor thesis, and I was intereste in make it reusable, if you re interexted mail to me.
Thank you
Cocconat
