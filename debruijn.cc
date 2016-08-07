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

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "main.h"

using namespace std;

void deBruijn(unsigned int alphabet_size, unsigned char * de_bruijn_seq, unsigned char * db, unsigned int factor_length, unsigned int t, unsigned int p) 
{

	static int count = 0;

	if ( t > factor_length )
	{
		if ( factor_length % p == 0 )
		{
			for(int i= 1; i < p+1;  i++)
			{

                		de_bruijn_seq[count] = db[i];
				count++;
			}
		}
	}
        else
	{
		db[t] =  db[t - p];
		deBruijn(alphabet_size, de_bruijn_seq, db, factor_length, t+1, p);

		for ( int j= db[t-p]-'0' + 1;  j< alphabet_size; j++)
		{
		        db[t] = j+'0';
		        deBruijn(alphabet_size, de_bruijn_seq, db, factor_length, t+1, t);
		}
	}
}
