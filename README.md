# Brainfuck

Brainfuck is an esoteric programming language created in 1993 by Urban Müller.

## build
```
make
```

## run script
```
./bf testing/Hello.bf
```
output
```
Hello World!
```

## test results

```
$ ./bf testing/Hello.bf 
Hello World!
```

```
$ ./bf testing/Beer.bf 
99 Bottles of beer on the wall
99 Bottles of beer
Take one down and pass it around
98 Bottles of beer on the wall

98 Bottles of beer on the wall
98 Bottles of beer
Take one down and pass it around
97 Bottles of beer on the wall

...

3 Bottles of beer on the wall
3 Bottles of beer
Take one down and pass it around
2 Bottles of beer on the wall

2 Bottles of beer on the wall
2 Bottles of beer
Take one down and pass it around
1 Bottle of beer on the wall

1 Bottle of beer on the wall
1 Bottle of beer
Take one down and pass it around
0 Bottles of beer on the wall
```

```
$ ./bf testing/Hanoi.bf
                          Towers of Hanoi in Brainf*ck
              Written by Clifford Wolf <http://www.clifford.at/bfcpu/>

                                                          xXx
                                                        xXXXXXx
                                                      xXXXXXXXXXx
                                                    xXXXXXXXXXXXXXx
                                                  xXXXXXXXXXXXXXXXXXx
                                                xXXXXXXXXXXXXXXXXXXXXXx
                                              xXXXXXXXXXXXXXXXXXXXXXXXXXx
                                            xXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx
                                          xXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx
  -----------------------------------     -----------------------------------


                                           
                                             
                                               
                                                 
                                                   
                                                     
                                                       
                      -----------------------------------

```

