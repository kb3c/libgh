## libgh deployment side makefile
## Copyright(c) 2016, polarysekt
##################################


.PHONY: prepare


prepare:
	gunzip --force -k 1.1.3.1/libgh*.gz
	gunzip --force -k 1.1.3.2/libgh*.gz


