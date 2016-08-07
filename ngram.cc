/**
    dbFLASM
    Copyright (C) 2016 Lorraine A. K. Ayad and Solon P. Pissis

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include "main.h"

void permutations(unsigned char * s, int alphabet_size, int q_gram, unsigned int * index, int depth, unsigned char ** combinations)
{
    static int count = 0;
    if (depth == q_gram)
    {   
        for (int i = 0; i < q_gram; ++i)
        {
	    combinations[count][i] = s[index[i]]+'0';
	    
        }	
	count++;
        return;
    }
   
    for (int i = 0; i <alphabet_size ; ++i)
    {
        index[depth] =  i;
        permutations(s, alphabet_size, q_gram, index, depth+1, combinations);
    }

}

