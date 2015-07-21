# -*- coding: utf-8 -*-
import random

def text_acquire(origin):
    fp=open(origin,'r')
    return fp.read()

def sent_splitter (text):
    words=[]
    words=text.split(',')
    words=[line.strip() for line in words ]
    return words


#generazione di frasi random (sentìs è un elemento della lista sentences
def randomize (sents):
    string=''
    words=sents.split()
    words=random.sample(words,len(words))
    for word in words:
        string += word +' '
    return string.strip()

def ghost_writer (fo,sents):
    fout= open(fo, 'w')
    for sent in sents:
        fout.write (sent)
 #       fout.write (', ')


def code_entropy (input_lista):
    return math.log(input_lista.__len__(),2)

def max_entropy (input_lista):
    #estimate entropy wirth shannon formula
    prob={x:float(input_lista[x])/sum(input_lista.values()) for x in input_lista}
    log_prob= {x:math.log(float(input_lista[x])/sum(input_lista.values()),2) for x in input_lista}
    Hraw=0
    for x in lista:
        Hraw -=prob[x]*log_prob[x]
    return Hraw, prob, log_prob

def clean_format(string,dot):
    for x in ['!','?',';',':',';','.']:
        string=string.replace(x,dot)
    string=string.replace('\n',' ').replace('-',' ')
    for x in ['\'','\"','%','*','$','&','(',')','-','/','[',']','_','@','\n']:
        string=string.replace(x, '')
    return string.lower()
