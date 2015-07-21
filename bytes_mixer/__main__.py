# -*- coding: utf-8 -*-
import sys
import random, functools
dim=int(sys.argv[2])

text=open(sys.argv[1],'r')
#sys.stdout=os.fdopen(sys.stdout.fileno(),newline=None)

#mischiare blocchi da n (dim) parole
def block_mixer (text,dim):
#    text=clean_format(text,',').replace(',','')
	a = range(0,len(text)/dim)
	random.shuffle(a)
	r=int (random.randint(0,dim))
	blocks=[text[r+int(x)*dim:r+int(1+x)*dim] for x in a]
	return blocks

for x in block_mixer(text.read(),dim):
	sys.stdout.write(x)

