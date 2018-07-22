#include <bits/stdc++.h>
using namespace std;
string checker[9][9];
void scopy(int s1[9][9], int s2[9][9])
{
//copies values to grid s2 to grid s1
for(int i=0;i<9;i++)
for(int j=0;j<9;j++)
s1[i][j]=s2[i][j];
}

void printsudoku(int sudoku[9][9])
{
//prints the grid
	for(int i=0; i<9; i++)
	    {
		for(int j=0; j<9; j++)
		    cout<<sudoku[i][j]<<" ";
		cout<<"\n";
	    }
	cout<<"\n";
}
int invalid(int sudoku[9][9])
{
//checks if current state of unfilled sudoku is valid for further filling or not
	int c[10];
	for(int i=0;i<9;i++)
	{
		for(int p=0;p<=9;p++)
			c[p]=0;
		for(int j=0;j<9;j++)
			c[sudoku[i][j]]++;
		for(int p=1;p<=9;p++)
			if (c[p]>1)
				return (1);
	}
	for(int i=0;i<9;i++)
	{
		for(int p=0;p<=9;p++)
			c[p]=0;
		for(int j=0;j<9;j++)
			c[sudoku[j][i]]++;
		for(int p=1;p<=9;p++)
			if (c[p]>1)
				return (1);
	}
	return 0;

}
int validate(int sudoku[9][9])
{
//validates the completely filled grid to check if answer is correct

   for (int i=0;i<9;i++)
   {
      int a[9]={0,0,0,0,0,0,0,0,0};
      for (int j=0;j<9;j++)
      a[sudoku[i][j]-1]=1;
      for(int it=0;it<9;it++)
      if (a[it]!=1)
      return -1;
   }

   for (int i=0;i<9;i++)
   {
      int a[9]={0,0,0,0,0,0,0,0,0};
      for (int j=0;j<9;j++)
      a[sudoku[j][i]-1]=1;
      for(int it=0;it<9;it++)
      if (a[it]!=1)
      return -1;
   }


   return 1;
}
void take_input(int sudoku[9][9])
{
//takes input grid from user
//grid can be manually assigned fro this function itself
	cout<<"Enter the 9X9 Sudoku to solve\nEnter all the numbers row by row, seperated by spaces.\n For cells that are empty, enter zero.\n\n";


/*
To check a sample, comment lines 88-90,uncomment that sample, and uncomment lines 134-136, and comment 141-151

*/
	for(int i=0; i<9; i++)
	for(int j=0; j<9; j++)
	    cin>>sudoku[i][j];



	/*int sample[9][9]=
	{
	{0,2,0,6,0,8,0,0,0},
	{5,8,0,0,0,9,7,0,0},
	{0,0,0,0,4,0,0,0,0},
	{3,7,0,0,0,0,5,0,0},
	{6,0,0,0,0,0,0,0,4},
	{0,0,8,0,0,0,0,1,3},
	{0,0,0,0,2,0,0,0,0},
	{0,0,9,8,0,0,0,3,6},
	{0,0,0,3,0,6,0,9,0}
	};

    int sample[9][9]=
    {
    {8,0,0,0,0,0,0,0,0},
    {0,0,3,6,0,0,0,0,0},
    {0,7,0,0,9,0,2,0,0},
    {0,5,0,0,0,7,0,0,0},
    {0,0,0,0,4,5,7,0,0},
    {0,0,0,1,0,0,0,3,0},
    {0,0,1,0,0,0,0,6,8},
    {0,0,8,5,0,0,0,1,0},
    {0,9,0,0,0,0,4,0,0}
    };

    int sample[9][9]=
    {
    {0,0,5,3,0,0,0,0,0},
    {8,0,0,0,0,0,0,2,0},
    {0,7,0,0,1,0,5,0,0},
    {4,0,0,0,0,5,3,0,0},
    {0,1,0,0,7,0,0,0,6},
    {0,0,3,2,0,0,0,8,0},
    {0,6,0,5,0,0,0,0,9},
    {0,0,4,0,0,0,0,3,0},
    {0,0,0,0,0,9,7,0,0},
    };
    */


    /*
    for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
    sudoku[i][j]=sample[i][j];
    */

	cout<<"This is the Sudoku you have entered.\n\n";
	printsudoku(sudoku);
	int c=0;
	while(c!=5)
	{
        cout<<"If you have entered correct question, enter 5. Otherwise enter any other number to change particular entry\n";
        cin>>c;
        if (c!=5)
        {
        int x,y; cout<<"Enter x and y coordinate seperated by space. (0 based index)\n"; cin>>x>>y; cout<<"Enter new number for this cell\n";
        cin>>sudoku[x][y];
        }
	}
	//cout<<"\n\nI will now solve it. \nTime for Plan A.\n\n";
}
int isnotingrid(int num, int i, int j, int sudoku[9][9])
{
//checks if number num at position i,j of 9X9 grid is present anywhere else in its 3X3 grid or not
	int gsti=(i/3), gstj=(j/3);
	for(int m=3*gsti;m<(3*gsti)+3;m++)
	{
	for(int n=3*gstj;n<(3*gstj)+3;n++)
	if (sudoku[m][n]==num)
	return (-1);
	}
	return (1);
}
int isnotinrow(int num, int i, int j, int sudoku[9][9])
{
//checks if number num at position i,j of grid is present anywhere else in row or not
	for(int m=0;m<9;m++)
	{
	if (sudoku[i][m]==num)
	return(-1);
	}
	return(1);
}
int isnotincolumn(int num, int i, int j, int sudoku[9][9])
{
//checks if number num at position i,j of grid is present anywhere else in column or not
	for(int m=0;m<9;m++)
	{
	if (sudoku[m][j]==num)
	return (-1);
	}
	return (1);
}
void solofill(int sudoku[9][9], int i, int j)
{
//fills a number at a position if only one number is possible at that position
        int numtofill=0; int c1=0;
        for(int f=1; f<=9; f++)
        {
            if (isnotingrid(f,i,j,sudoku)==1 && isnotinrow(f,i,j,sudoku)==1 && isnotincolumn(f,i,j,sudoku)==1)
                {
                    numtofill=f; c1++;
                }
        }
        if (c1==1)
        { sudoku[i][j]=numtofill; checker[i][j]="solofill";}
}
void rejfillgrid(int sudoku[9][9], int i, int j)
{
//fills a number at a position if that number has been rejected by all other empty positions in its 3X3 grid
	int gsti=(i/3), gstj=(j/3);

	for(int f=1;f<=9;f++)
	{
		int c1=0;
		for(int m=3*gsti; m<(3*gsti)+3; m++)
		{
			for(int n=3*gstj; n<(3*gstj)+3; n++)
			if ( !(m==i && n==j) && (sudoku[m][n]==f || ( isnotingrid(f,m,n,sudoku)==1 && isnotinrow(f,m,n,sudoku)==1 && isnotincolumn(f,m,n,sudoku)==1 )))
			c1++;
		}
		if (c1==0)
		{
			sudoku[i][j]=f; checker[i][j]="rejfillgrid"; break;
		}
	}
}
void rejfillcolumn(int sudoku[9][9], int i, int j)
{
//fills a number at a position if that number has been rejected by all other empty positions in its column
	for(int f=1;f<=9;f++)
	{
		int c1=0;
		for(int m=0;m<9;m++)
		if (m!=i && (sudoku[m][j]==f||( isnotingrid(f,m,j,sudoku)==1 && isnotinrow(f,m,j,sudoku)==1 && isnotincolumn(f,m,j,sudoku)==1 ) ))
		c1++;
		if (c1==0)
		{
			sudoku[i][j]=f; checker[i][j]="rejfillcolumn"; break;
		}

	}
}
void rejfillrow(int sudoku[9][9], int i, int j)
{
//fills a number at a position if that number has been rejected by all other empty positions in its row
	for(int f=1;f<=9;f++)
	{
		int c1=0;
		for(int n=0;n<9;n++)
		if (n!=j && (sudoku[i][n]==f || ( isnotingrid(f,i,n,sudoku)==1 && isnotinrow(f,i,n,sudoku)==1 && isnotincolumn(f,i,n,sudoku)==1 )))
		c1++;
		if (c1==0)
		{
			sudoku[i][j]=f; checker[i][j]="rejfillrow"; break;
		}

	}
}
void rejfill(int sudoku[9][9], int i, int j)
{
//calls functions which fill using number rejection, ie, if a number has only one possible position in a row, column, or grid
	rejfillgrid(sudoku,i,j);
	if (sudoku[i][j]==0)
	rejfillcolumn(sudoku,i,j);
	if (sudoku[i][j]==0)
	rejfillrow(sudoku,i,j);
}


int bruteattack(int s[9][9])
{
//finds out available options for each unfilled cell, and starts by checking each option.
//proceeds for further steps only if the current state of Sudoku is valid (solvable state)
//if filling a cell (i,j) with numner n voids its solvability,then all the possible solutions with n at (i,j) are skipped
//after encountering invalid number, the grid is reverted to last visited solvable state

    int s00[9][9];
    scopy(s00,s);

    vector <int> options00;
    if (s00[0][0]!=0)
        options00.push_back(s00[0][0]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,0,0,s00)==1 && isnotincolumn(f,0,0,s00)==1 && isnotinrow(f,0,0,s00)==1)
                options00.push_back(f);
    }
    for(int it_00=0;it_00<options00.size();it_00++)
    {
    s00[0][0]=options00[it_00];
    int s01[9][9];
    scopy(s01,s00);
    vector <int> options01;
    if (s01[0][1]!=0)
        options01.push_back(s01[0][1]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,0,1,s01)==1 && isnotincolumn(f,0,1,s01)==1 && isnotinrow(f,0,1,s01)==1)
                options01.push_back(f);
    }
    for(int it_01=0;it_01<options01.size();it_01++)
    {
    s01[0][1]=options01[it_01];
    int s02[9][9];
    if (0==0 && 2==0)
    scopy(s02,s);
    else if (2==0)
    scopy(s02,s);
    else
    scopy(s02,s01);
    vector <int> options02;
    if (s02[0][2]!=0)
        options02.push_back(s02[0][2]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,0,2,s02)==1 && isnotincolumn(f,0,2,s02)==1 && isnotinrow(f,0,2,s02)==1)
                options02.push_back(f);
    }
    for(int it_02=0;it_02<options02.size();it_02++)
    {
    s02[0][2]=options02[it_02];
    int s03[9][9];

    scopy(s03,s02);
    vector <int> options03;
    if (s03[0][3]!=0)
        options03.push_back(s03[0][3]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,0,3,s03)==1 && isnotincolumn(f,0,3,s03)==1 && isnotinrow(f,0,3,s03)==1)
                options03.push_back(f);
    }
    for(int it_03=0;it_03<options03.size();it_03++)
    {
    s03[0][3]=options03[it_03];
    int s04[9][9];
    if (0==0 && 4==0)
    scopy(s04,s);
    else if (4==0)
    scopy(s04,s);
    else
    scopy(s04,s03);
    vector <int> options04;
    if (s04[0][4]!=0)
        options04.push_back(s04[0][4]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,0,4,s04)==1 && isnotincolumn(f,0,4,s04)==1 && isnotinrow(f,0,4,s04)==1)
                options04.push_back(f);
    }
    for(int it_04=0;it_04<options04.size();it_04++)
    {
    s04[0][4]=options04[it_04];
    int s05[9][9];
    scopy(s05,s04);
    vector <int> options05;
    if (s05[0][5]!=0)
        options05.push_back(s05[0][5]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,0,5,s05)==1 && isnotincolumn(f,0,5,s05)==1 && isnotinrow(f,0,5,s05)==1)
                options05.push_back(f);
    }
    for(int it_05=0;it_05<options05.size();it_05++)
    {
    s05[0][5]=options05[it_05];
    int s06[9][9];
    if (0==0 && 6==0)
    scopy(s06,s);
    else if (6==0)
    scopy(s06,s);
    else
    scopy(s06,s05);
    vector <int> options06;
    if (s06[0][6]!=0)
        options06.push_back(s06[0][6]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,0,6,s06)==1 && isnotincolumn(f,0,6,s06)==1 && isnotinrow(f,0,6,s06)==1)
                options06.push_back(f);
    }
    for(int it_06=0;it_06<options06.size();it_06++)
    {
    s06[0][6]=options06[it_06];
    int s07[9][9];
    if (0==0 && 7==0)
    scopy(s07,s);
    else
    scopy(s07,s06);
    vector <int> options07;
    if (s07[0][7]!=0)
        options07.push_back(s07[0][7]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,0,7,s07)==1 && isnotincolumn(f,0,7,s07)==1 && isnotinrow(f,0,7,s07)==1)
                options07.push_back(f);
    }
    for(int it_07=0;it_07<options07.size();it_07++)
    {
    s07[0][7]=options07[it_07];
    int s08[9][9];
    if (0==0 && 8==0)
    scopy(s08,s);
    else if (8==0)
    scopy(s08,s);
    else
    scopy(s08,s07);
    vector <int> options08;
    if (s08[0][8]!=0)
        options08.push_back(s08[0][8]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,0,8,s08)==1 && isnotincolumn(f,0,8,s08)==1 && isnotinrow(f,0,8,s08)==1)
                options08.push_back(f);
    }
    for(int it_08=0;it_08<options08.size();it_08++)
    {
    s08[0][8]=options08[it_08];
    int s10[9][9];
    if (1==0 && 0==0)
    scopy(s10,s);
    else if (0==0)
    scopy(s10,s08);
    else
    scopy(s10,s);
    vector <int> options10;
    if (s10[1][0]!=0)
        options10.push_back(s10[1][0]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,1,0,s10)==1 && isnotincolumn(f,1,0,s10)==1 && isnotinrow(f,1,0,s10)==1)
                options10.push_back(f);
    }
    for(int it_10=0;it_10<options10.size();it_10++)
    {
    s10[1][0]=options10[it_10];
    int s11[9][9];
    if (1==0 && 1==0)
    scopy(s11,s);
    else if (1==0)
    scopy(s11,s08);
    else
    scopy(s11,s10);
    vector <int> options11;
    if (s11[1][1]!=0)
        options11.push_back(s11[1][1]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,1,1,s11)==1 && isnotincolumn(f,1,1,s11)==1 && isnotinrow(f,1,1,s11)==1)
                options11.push_back(f);
    }
    for(int it_11=0;it_11<options11.size();it_11++)
    {
    s11[1][1]=options11[it_11];
    int s12[9][9];
    if (1==0 && 2==0)
    scopy(s12,s);
    else if (2==0)
    scopy(s12,s08);
    else
    scopy(s12,s11);
    vector <int> options12;
    if (s12[1][2]!=0)
        options12.push_back(s12[1][2]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,1,2,s12)==1 && isnotincolumn(f,1,2,s12)==1 && isnotinrow(f,1,2,s12)==1)
                options12.push_back(f);
    }
    for(int it_12=0;it_12<options12.size();it_12++)
    {
    s12[1][2]=options12[it_12];
    int s13[9][9];
    if (1==0 && 3==0)
    scopy(s13,s);
    else if (3==0)
    scopy(s13,s08);
    else
    scopy(s13,s12);
    vector <int> options13;
    if (s13[1][3]!=0)
        options13.push_back(s13[1][3]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,1,3,s13)==1 && isnotincolumn(f,1,3,s13)==1 && isnotinrow(f,1,3,s13)==1)
                options13.push_back(f);
    }
    for(int it_13=0;it_13<options13.size();it_13++)
    {
    s13[1][3]=options13[it_13];
    int s14[9][9];
    if (1==0 && 4==0)
    scopy(s14,s);
    else if (4==0)
    scopy(s14,s08);
    else
    scopy(s14,s13);
    vector <int> options14;
    if (s14[1][4]!=0)
        options14.push_back(s14[1][4]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,1,4,s14)==1 && isnotincolumn(f,1,4,s14)==1 && isnotinrow(f,1,4,s14)==1)
                options14.push_back(f);
    }
    for(int it_14=0;it_14<options14.size();it_14++)
    {
    s14[1][4]=options14[it_14];
    int s15[9][9];
    if (1==0 && 5==0)
    scopy(s15,s);
    else if (5==0)
    scopy(s15,s08);
    else
    scopy(s15,s14);
    vector <int> options15;
    if (s15[1][5]!=0)
        options15.push_back(s15[1][5]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,1,5,s15)==1 && isnotincolumn(f,1,5,s15)==1 && isnotinrow(f,1,5,s15)==1)
                options15.push_back(f);
    }
    for(int it_15=0;it_15<options15.size();it_15++)
    {
    s15[1][5]=options15[it_15];
    int s16[9][9];
    if (1==0 && 6==0)
    scopy(s16,s);
    else if (6==0)
    scopy(s16,s08);
    else
    scopy(s16,s15);
    vector <int> options16;
    if (s16[1][6]!=0)
        options16.push_back(s16[1][6]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,1,6,s16)==1 && isnotincolumn(f,1,6,s16)==1 && isnotinrow(f,1,6,s16)==1)
                options16.push_back(f);
    }
    for(int it_16=0;it_16<options16.size();it_16++)
    {
    s16[1][6]=options16[it_16];
    int s17[9][9];
    if (1==0 && 7==0)
    scopy(s17,s);
    else if (7==0)
    scopy(s17,s08);
    else
    scopy(s17,s16);
    vector <int> options17;
    if (s17[1][7]!=0)
        options17.push_back(s17[1][7]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,1,7,s17)==1 && isnotincolumn(f,1,7,s17)==1 && isnotinrow(f,1,7,s17)==1)
                options17.push_back(f);
    }
    for(int it_17=0;it_17<options17.size();it_17++)
    {
    s17[1][7]=options17[it_17];
    int s18[9][9];
    if (1==0 && 8==0)
    scopy(s18,s);
    else if (8==0)
    scopy(s18,s08);
    else
    scopy(s18,s17);
    vector <int> options18;
    if (s18[1][8]!=0)
        options18.push_back(s18[1][8]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,1,8,s18)==1 && isnotincolumn(f,1,8,s18)==1 && isnotinrow(f,1,8,s18)==1)
                options18.push_back(f);
    }
    for(int it_18=0;it_18<options18.size();it_18++)
    {
    s18[1][8]=options18[it_18];
    int s20[9][9];
    if (2==0 && 0==0)
    scopy(s20,s);
    else if (0==0)
    scopy(s20,s18);
    else
    scopy(s20,s20);
    vector <int> options20;
    if (s20[2][0]!=0)
        options20.push_back(s20[2][0]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,2,0,s20)==1 && isnotincolumn(f,2,0,s20)==1 && isnotinrow(f,2,0,s20)==1)
                options20.push_back(f);
    }
    for(int it_20=0;it_20<options20.size();it_20++)
    {
    s20[2][0]=options20[it_20];
    int s21[9][9];
    if (2==0 && 1==0)
    scopy(s21,s);
    else if (1==0)
    scopy(s21,s18);
    else
    scopy(s21,s20);
    vector <int> options21;
    if (s21[2][1]!=0)
        options21.push_back(s21[2][1]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,2,1,s21)==1 && isnotincolumn(f,2,1,s21)==1 && isnotinrow(f,2,1,s21)==1)
                options21.push_back(f);
    }
    for(int it_21=0;it_21<options21.size();it_21++)
    {
    s21[2][1]=options21[it_21];
    int s22[9][9];
    if (2==0 && 2==0)
    scopy(s22,s);
    else if (2==0)
    scopy(s22,s18);
    else
    scopy(s22,s21);
    vector <int> options22;
    if (s22[2][2]!=0)
        options22.push_back(s22[2][2]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,2,2,s22)==1 && isnotincolumn(f,2,2,s22)==1 && isnotinrow(f,2,2,s22)==1)
                options22.push_back(f);
    }
    for(int it_22=0;it_22<options22.size();it_22++)
    {
    s22[2][2]=options22[it_22];
    int s23[9][9];
    if (2==0 && 3==0)
    scopy(s23,s);
    else if (3==0)
    scopy(s23,s18);
    else
    scopy(s23,s22);
    vector <int> options23;
    if (s23[2][3]!=0)
        options23.push_back(s23[2][3]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,2,3,s23)==1 && isnotincolumn(f,2,3,s23)==1 && isnotinrow(f,2,3,s23)==1)
                options23.push_back(f);
    }
    for(int it_23=0;it_23<options23.size();it_23++)
    {
    s23[2][3]=options23[it_23];
    int s24[9][9];
    if (2==0 && 4==0)
    scopy(s24,s);
    else if (4==0)
    scopy(s24,s18);
    else
    scopy(s24,s23);
    vector <int> options24;
    if (s24[2][4]!=0)
        options24.push_back(s24[2][4]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,2,4,s24)==1 && isnotincolumn(f,2,4,s24)==1 && isnotinrow(f,2,4,s24)==1)
                options24.push_back(f);
    }
    for(int it_24=0;it_24<options24.size();it_24++)
    {
    s24[2][4]=options24[it_24];
    int s25[9][9];
    if (2==0 && 5==0)
    scopy(s25,s);
    else if (5==0)
    scopy(s25,s18);
    else
    scopy(s25,s24);
    vector <int> options25;
    if (s25[2][5]!=0)
        options25.push_back(s25[2][5]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,2,5,s25)==1 && isnotincolumn(f,2,5,s25)==1 && isnotinrow(f,2,5,s25)==1)
                options25.push_back(f);
    }
    for(int it_25=0;it_25<options25.size();it_25++)
    {
    s25[2][5]=options25[it_25];
    int s26[9][9];
    if (2==0 && 6==0)
    scopy(s26,s);
    else if (6==0)
    scopy(s26,s18);
    else
    scopy(s26,s25);
    vector <int> options26;
    if (s26[2][6]!=0)
        options26.push_back(s26[2][6]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,2,6,s26)==1 && isnotincolumn(f,2,6,s26)==1 && isnotinrow(f,2,6,s26)==1)
                options26.push_back(f);
    }
    for(int it_26=0;it_26<options26.size();it_26++)
    {
    s26[2][6]=options26[it_26];
    int s27[9][9];
    if (2==0 && 7==0)
    scopy(s27,s);
    else if (7==0)
    scopy(s27,s18);
    else
    scopy(s27,s26);
    vector <int> options27;
    if (s27[2][7]!=0)
        options27.push_back(s27[2][7]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,2,7,s27)==1 && isnotincolumn(f,2,7,s27)==1 && isnotinrow(f,2,7,s27)==1)
                options27.push_back(f);
    }
    for(int it_27=0;it_27<options27.size();it_27++)
    {
    s27[2][7]=options27[it_27];
    int s28[9][9];
    if (2==0 && 8==0)
    scopy(s28,s);
    else if (8==0)
    scopy(s28,s18);
    else
    scopy(s28,s27);
    vector <int> options28;
    if (s28[2][8]!=0)
        options28.push_back(s28[2][8]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,2,8,s28)==1 && isnotincolumn(f,2,8,s28)==1 && isnotinrow(f,2,8,s28)==1)
                options28.push_back(f);
    }
    for(int it_28=0;it_28<options28.size();it_28++)
    {
    s28[2][8]=options28[it_28];
    int s30[9][9];
    if (3==0 && 0==0)
    scopy(s30,s);
    else if (0==0)
    scopy(s30,s28);
    else
    scopy(s30,s);
    vector <int> options30;
    if (s30[3][0]!=0)
        options30.push_back(s30[3][0]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,3,0,s30)==1 && isnotincolumn(f,3,0,s30)==1 && isnotinrow(f,3,0,s30)==1)
                options30.push_back(f);
    }
    for(int it_30=0;it_30<options30.size();it_30++)
    {
    s30[3][0]=options30[it_30];
    int s31[9][9];
    if (3==0 && 1==0)
    scopy(s31,s);
    else if (1==0)
    scopy(s31,s28);
    else
    scopy(s31,s30);
    vector <int> options31;
    if (s31[3][1]!=0)
        options31.push_back(s31[3][1]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,3,1,s31)==1 && isnotincolumn(f,3,1,s31)==1 && isnotinrow(f,3,1,s31)==1)
                options31.push_back(f);
    }
    for(int it_31=0;it_31<options31.size();it_31++)
    {
    s31[3][1]=options31[it_31];
    int s32[9][9];
    if (3==0 && 2==0)
    scopy(s32,s);
    else if (2==0)
    scopy(s32,s28);
    else
    scopy(s32,s31);
    vector <int> options32;
    if (s32[3][2]!=0)
        options32.push_back(s32[3][2]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,3,2,s32)==1 && isnotincolumn(f,3,2,s32)==1 && isnotinrow(f,3,2,s32)==1)
                options32.push_back(f);
    }
    for(int it_32=0;it_32<options32.size();it_32++)
    {
    s32[3][2]=options32[it_32];
    int s33[9][9];
    if (3==0 && 3==0)
    scopy(s33,s);
    else if (3==0)
    scopy(s33,s28);
    else
    scopy(s33,s32);
    vector <int> options33;
    if (s33[3][3]!=0)
        options33.push_back(s33[3][3]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,3,3,s33)==1 && isnotincolumn(f,3,3,s33)==1 && isnotinrow(f,3,3,s33)==1)
                options33.push_back(f);
    }
    for(int it_33=0;it_33<options33.size();it_33++)
    {
    s33[3][3]=options33[it_33];
    int s34[9][9];
    if (3==0 && 4==0)
    scopy(s34,s);
    else if (4==0)
    scopy(s34,s28);
    else
    scopy(s34,s33);
    vector <int> options34;
    if (s34[3][4]!=0)
        options34.push_back(s34[3][4]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,3,4,s34)==1 && isnotincolumn(f,3,4,s34)==1 && isnotinrow(f,3,4,s34)==1)
                options34.push_back(f);
    }
    for(int it_34=0;it_34<options34.size();it_34++)
    {
    s34[3][4]=options34[it_34];
    int s35[9][9];
    if (3==0 && 5==0)
    scopy(s35,s);
    else if (5==0)
    scopy(s35,s28);
    else
    scopy(s35,s34);
    vector <int> options35;
    if (s35[3][5]!=0)
        options35.push_back(s35[3][5]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,3,5,s35)==1 && isnotincolumn(f,3,5,s35)==1 && isnotinrow(f,3,5,s35)==1)
                options35.push_back(f);
    }
    for(int it_35=0;it_35<options35.size();it_35++)
    {
    s35[3][5]=options35[it_35];
    int s36[9][9];
    if (3==0 && 6==0)
    scopy(s36,s);
    else if (6==0)
    scopy(s36,s28);
    else
    scopy(s36,s35);
    vector <int> options36;
    if (s36[3][6]!=0)
        options36.push_back(s36[3][6]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,3,6,s36)==1 && isnotincolumn(f,3,6,s36)==1 && isnotinrow(f,3,6,s36)==1)
                options36.push_back(f);
    }
    for(int it_36=0;it_36<options36.size();it_36++)
    {
    s36[3][6]=options36[it_36];
    int s37[9][9];
    if (3==0 && 7==0)
    scopy(s37,s);
    else if (7==0)
    scopy(s37,s28);
    else
    scopy(s37,s36);
    vector <int> options37;
    if (s37[3][7]!=0)
        options37.push_back(s37[3][7]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,3,7,s37)==1 && isnotincolumn(f,3,7,s37)==1 && isnotinrow(f,3,7,s37)==1)
                options37.push_back(f);
    }
    for(int it_37=0;it_37<options37.size();it_37++)
    {
    s37[3][7]=options37[it_37];
    int s38[9][9];
    if (3==0 && 8==0)
    scopy(s38,s);
    else if (8==0)
    scopy(s38,s28);
    else
    scopy(s38,s37);
    vector <int> options38;
    if (s38[3][8]!=0)
        options38.push_back(s38[3][8]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,3,8,s38)==1 && isnotincolumn(f,3,8,s38)==1 && isnotinrow(f,3,8,s38)==1)
                options38.push_back(f);
    }
    for(int it_38=0;it_38<options38.size();it_38++)
    {
    s38[3][8]=options38[it_38];
    int s40[9][9];
    if (4==0 && 0==0)
    scopy(s40,s);
    else if (0==0)
    scopy(s40,s38);
    else
    scopy(s40,s40);
    vector <int> options40;
    if (s40[4][0]!=0)
        options40.push_back(s40[4][0]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,4,0,s40)==1 && isnotincolumn(f,4,0,s40)==1 && isnotinrow(f,4,0,s40)==1)
                options40.push_back(f);
    }
    for(int it_40=0;it_40<options40.size();it_40++)
    {
    s40[4][0]=options40[it_40];
    int s41[9][9];
    if (4==0 && 1==0)
    scopy(s41,s);
    else if (1==0)
    scopy(s41,s38);
    else
    scopy(s41,s40);
    vector <int> options41;
    if (s41[4][1]!=0)
        options41.push_back(s41[4][1]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,4,1,s41)==1 && isnotincolumn(f,4,1,s41)==1 && isnotinrow(f,4,1,s41)==1)
                options41.push_back(f);
    }
    for(int it_41=0;it_41<options41.size();it_41++)
    {
    s41[4][1]=options41[it_41];
    int s42[9][9];
    if (4==0 && 2==0)
    scopy(s42,s);
    else if (2==0)
    scopy(s42,s38);
    else
    scopy(s42,s41);
    vector <int> options42;
    if (s42[4][2]!=0)
        options42.push_back(s42[4][2]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,4,2,s42)==1 && isnotincolumn(f,4,2,s42)==1 && isnotinrow(f,4,2,s42)==1)
                options42.push_back(f);
    }
    for(int it_42=0;it_42<options42.size();it_42++)
    {
    s42[4][2]=options42[it_42];
    int s43[9][9];
    if (4==0 && 3==0)
    scopy(s43,s);
    else if (3==0)
    scopy(s43,s38);
    else
    scopy(s43,s42);
    vector <int> options43;
    if (s43[4][3]!=0)
        options43.push_back(s43[4][3]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,4,3,s43)==1 && isnotincolumn(f,4,3,s43)==1 && isnotinrow(f,4,3,s43)==1)
                options43.push_back(f);
    }
    for(int it_43=0;it_43<options43.size();it_43++)
    {
    s43[4][3]=options43[it_43];
    int s44[9][9];
    if (4==0 && 4==0)
    scopy(s44,s);
    else if (4==0)
    scopy(s44,s38);
    else
    scopy(s44,s43);
    vector <int> options44;
    if (s44[4][4]!=0)
        options44.push_back(s44[4][4]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,4,4,s44)==1 && isnotincolumn(f,4,4,s44)==1 && isnotinrow(f,4,4,s44)==1)
                options44.push_back(f);
    }
    for(int it_44=0;it_44<options44.size();it_44++)
    {
    s44[4][4]=options44[it_44];
    int s45[9][9];
    if (4==0 && 5==0)
    scopy(s45,s);
    else if (5==0)
    scopy(s45,s38);
    else
    scopy(s45,s44);
    vector <int> options45;
    if (s45[4][5]!=0)
        options45.push_back(s45[4][5]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,4,5,s45)==1 && isnotincolumn(f,4,5,s45)==1 && isnotinrow(f,4,5,s45)==1)
                options45.push_back(f);
    }
    for(int it_45=0;it_45<options45.size();it_45++)
    {
    s45[4][5]=options45[it_45];
    int s46[9][9];
    if (4==0 && 6==0)
    scopy(s46,s);
    else if (6==0)
    scopy(s46,s38);
    else
    scopy(s46,s45);
    vector <int> options46;
    if (s46[4][6]!=0)
        options46.push_back(s46[4][6]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,4,6,s46)==1 && isnotincolumn(f,4,6,s46)==1 && isnotinrow(f,4,6,s46)==1)
                options46.push_back(f);
    }
    for(int it_46=0;it_46<options46.size();it_46++)
    {
    s46[4][6]=options46[it_46];
    int s47[9][9];
    if (4==0 && 7==0)
    scopy(s47,s);
    else if (7==0)
    scopy(s47,s38);
    else
    scopy(s47,s46);
    vector <int> options47;
    if (s47[4][7]!=0)
        options47.push_back(s47[4][7]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,4,7,s47)==1 && isnotincolumn(f,4,7,s47)==1 && isnotinrow(f,4,7,s47)==1)
                options47.push_back(f);
    }
    for(int it_47=0;it_47<options47.size();it_47++)
    {
    s47[4][7]=options47[it_47];
    int s48[9][9];
    if (4==0 && 8==0)
    scopy(s48,s);
    else if (8==0)
    scopy(s48,s38);
    else
    scopy(s48,s47);
    vector <int> options48;
    if (s48[4][8]!=0)
        options48.push_back(s48[4][8]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,4,8,s48)==1 && isnotincolumn(f,4,8,s48)==1 && isnotinrow(f,4,8,s48)==1)
                options48.push_back(f);
    }
    for(int it_48=0;it_48<options48.size();it_48++)
    {
    s48[4][8]=options48[it_48];
    int s50[9][9];
    if (5==0 && 0==0)
    scopy(s50,s);
    else if (0==0)
    scopy(s50,s48);
    else
    scopy(s50,s50);
    vector <int> options50;
    if (s50[5][0]!=0)
        options50.push_back(s50[5][0]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,5,0,s50)==1 && isnotincolumn(f,5,0,s50)==1 && isnotinrow(f,5,0,s50)==1)
                options50.push_back(f);
    }
    for(int it_50=0;it_50<options50.size();it_50++)
    {
    s50[5][0]=options50[it_50];
    int s51[9][9];
    if (5==0 && 1==0)
    scopy(s51,s);
    else if (1==0)
    scopy(s51,s48);
    else
    scopy(s51,s50);
    vector <int> options51;
    if (s51[5][1]!=0)
        options51.push_back(s51[5][1]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,5,1,s51)==1 && isnotincolumn(f,5,1,s51)==1 && isnotinrow(f,5,1,s51)==1)
                options51.push_back(f);
    }
    for(int it_51=0;it_51<options51.size();it_51++)
    {
    s51[5][1]=options51[it_51];
    int s52[9][9];
    if (5==0 && 2==0)
    scopy(s52,s);
    else if (2==0)
    scopy(s52,s48);
    else
    scopy(s52,s51);
    vector <int> options52;
    if (s52[5][2]!=0)
        options52.push_back(s52[5][2]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,5,2,s52)==1 && isnotincolumn(f,5,2,s52)==1 && isnotinrow(f,5,2,s52)==1)
                options52.push_back(f);
    }
    for(int it_52=0;it_52<options52.size();it_52++)
    {
    s52[5][2]=options52[it_52];
    int s53[9][9];
    if (5==0 && 3==0)
    scopy(s53,s);
    else if (3==0)
    scopy(s53,s48);
    else
    scopy(s53,s52);
    vector <int> options53;
    if (s53[5][3]!=0)
        options53.push_back(s53[5][3]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,5,3,s53)==1 && isnotincolumn(f,5,3,s53)==1 && isnotinrow(f,5,3,s53)==1)
                options53.push_back(f);
    }
    for(int it_53=0;it_53<options53.size();it_53++)
    {
    s53[5][3]=options53[it_53];
    int s54[9][9];
    if (5==0 && 4==0)
    scopy(s54,s);
    else if (4==0)
    scopy(s54,s48);
    else
    scopy(s54,s53);
    vector <int> options54;
    if (s54[5][4]!=0)
        options54.push_back(s54[5][4]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,5,4,s54)==1 && isnotincolumn(f,5,4,s54)==1 && isnotinrow(f,5,4,s54)==1)
                options54.push_back(f);
    }
    for(int it_54=0;it_54<options54.size();it_54++)
    {
    s54[5][4]=options54[it_54];
    int s55[9][9];
    if (5==0 && 5==0)
    scopy(s55,s);
    else if (5==0)
    scopy(s55,s48);
    else
    scopy(s55,s54);
    vector <int> options55;
    if (s55[5][5]!=0)
        options55.push_back(s55[5][5]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,5,5,s55)==1 && isnotincolumn(f,5,5,s55)==1 && isnotinrow(f,5,5,s55)==1)
                options55.push_back(f);
    }
    for(int it_55=0;it_55<options55.size();it_55++)
    {
    s55[5][5]=options55[it_55];
    int s56[9][9];
    if (5==0 && 6==0)
    scopy(s56,s);
    else if (6==0)
    scopy(s56,s48);
    else
    scopy(s56,s55);
    vector <int> options56;
    if (s56[5][6]!=0)
        options56.push_back(s56[5][6]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,5,6,s56)==1 && isnotincolumn(f,5,6,s56)==1 && isnotinrow(f,5,6,s56)==1)
                options56.push_back(f);
    }
    for(int it_56=0;it_56<options56.size();it_56++)
    {
    s56[5][6]=options56[it_56];
    int s57[9][9];
    if (5==0 && 7==0)
    scopy(s57,s);
    else if (7==0)
    scopy(s57,s48);
    else
    scopy(s57,s56);
    vector <int> options57;
    if (s57[5][7]!=0)
        options57.push_back(s57[5][7]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,5,7,s57)==1 && isnotincolumn(f,5,7,s57)==1 && isnotinrow(f,5,7,s57)==1)
                options57.push_back(f);
    }
    for(int it_57=0;it_57<options57.size();it_57++)
    {
    s57[5][7]=options57[it_57];
    int s58[9][9];
    if (5==0 && 8==0)
    scopy(s58,s);
    else if (8==0)
    scopy(s58,s48);
    else
    scopy(s58,s57);
    vector <int> options58;
    if (s58[5][8]!=0)
        options58.push_back(s58[5][8]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,5,8,s58)==1 && isnotincolumn(f,5,8,s58)==1 && isnotinrow(f,5,8,s58)==1)
                options58.push_back(f);
    }
    for(int it_58=0;it_58<options58.size();it_58++)
    {
    s58[5][8]=options58[it_58];
    int s60[9][9];
    if (6==0 && 0==0)
    scopy(s60,s);
    else if (0==0)
    scopy(s60,s58);
    else
    scopy(s60,s60);
    vector <int> options60;
    if (s60[6][0]!=0)
        options60.push_back(s60[6][0]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,6,0,s60)==1 && isnotincolumn(f,6,0,s60)==1 && isnotinrow(f,6,0,s60)==1)
                options60.push_back(f);
    }
    for(int it_60=0;it_60<options60.size();it_60++)
    {
    s60[6][0]=options60[it_60];
    int s61[9][9];
    if (6==0 && 1==0)
    scopy(s61,s);
    else if (1==0)
    scopy(s61,s58);
    else
    scopy(s61,s60);
    vector <int> options61;
    if (s61[6][1]!=0)
        options61.push_back(s61[6][1]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,6,1,s61)==1 && isnotincolumn(f,6,1,s61)==1 && isnotinrow(f,6,1,s61)==1)
                options61.push_back(f);
    }
    for(int it_61=0;it_61<options61.size();it_61++)
    {
    s61[6][1]=options61[it_61];
    int s62[9][9];
    if (6==0 && 2==0)
    scopy(s62,s);
    else if (2==0)
    scopy(s62,s58);
    else
    scopy(s62,s61);
    vector <int> options62;
    if (s62[6][2]!=0)
        options62.push_back(s62[6][2]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,6,2,s62)==1 && isnotincolumn(f,6,2,s62)==1 && isnotinrow(f,6,2,s62)==1)
                options62.push_back(f);
    }
    for(int it_62=0;it_62<options62.size();it_62++)
    {
    s62[6][2]=options62[it_62];
    int s63[9][9];
    if (6==0 && 3==0)
    scopy(s63,s);
    else if (3==0)
    scopy(s63,s58);
    else
    scopy(s63,s62);
    vector <int> options63;
    if (s63[6][3]!=0)
        options63.push_back(s63[6][3]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,6,3,s63)==1 && isnotincolumn(f,6,3,s63)==1 && isnotinrow(f,6,3,s63)==1)
                options63.push_back(f);
    }
    for(int it_63=0;it_63<options63.size();it_63++)
    {
    s63[6][3]=options63[it_63];
    int s64[9][9];
    if (6==0 && 4==0)
    scopy(s64,s);
    else if (4==0)
    scopy(s64,s58);
    else
    scopy(s64,s63);
    vector <int> options64;
    if (s64[6][4]!=0)
        options64.push_back(s64[6][4]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,6,4,s64)==1 && isnotincolumn(f,6,4,s64)==1 && isnotinrow(f,6,4,s64)==1)
                options64.push_back(f);
    }
    for(int it_64=0;it_64<options64.size();it_64++)
    {
    s64[6][4]=options64[it_64];
    int s65[9][9];
    if (6==0 && 5==0)
    scopy(s65,s);
    else if (5==0)
    scopy(s65,s58);
    else
    scopy(s65,s64);
    vector <int> options65;
    if (s65[6][5]!=0)
        options65.push_back(s65[6][5]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,6,5,s65)==1 && isnotincolumn(f,6,5,s65)==1 && isnotinrow(f,6,5,s65)==1)
                options65.push_back(f);
    }
    for(int it_65=0;it_65<options65.size();it_65++)
    {
    s65[6][5]=options65[it_65];
    int s66[9][9];
    if (6==0 && 6==0)
    scopy(s66,s);
    else if (6==0)
    scopy(s66,s58);
    else
    scopy(s66,s65);
    vector <int> options66;
    if (s66[6][6]!=0)
        options66.push_back(s66[6][6]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,6,6,s66)==1 && isnotincolumn(f,6,6,s66)==1 && isnotinrow(f,6,6,s66)==1)
                options66.push_back(f);
    }
    for(int it_66=0;it_66<options66.size();it_66++)
    {
    s66[6][6]=options66[it_66];
    int s67[9][9];
    if (6==0 && 7==0)
    scopy(s67,s);
    else if (7==0)
    scopy(s67,s58);
    else
    scopy(s67,s66);
    vector <int> options67;
    if (s67[6][7]!=0)
        options67.push_back(s67[6][7]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,6,7,s67)==1 && isnotincolumn(f,6,7,s67)==1 && isnotinrow(f,6,7,s67)==1)
                options67.push_back(f);
    }
    for(int it_67=0;it_67<options67.size();it_67++)
    {
    s67[6][7]=options67[it_67];
    int s68[9][9];
    if (6==0 && 8==0)
    scopy(s68,s);
    else if (8==0)
    scopy(s68,s58);
    else
    scopy(s68,s67);
    vector <int> options68;
    if (s68[6][8]!=0)
        options68.push_back(s68[6][8]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,6,8,s68)==1 && isnotincolumn(f,6,8,s68)==1 && isnotinrow(f,6,8,s68)==1)
                options68.push_back(f);
    }
    for(int it_68=0;it_68<options68.size();it_68++)
    {
    s68[6][8]=options68[it_68];
    int s70[9][9];
    if (7==0 && 0==0)
    scopy(s70,s);
    else if (0==0)
    scopy(s70,s68);
    else
    scopy(s70,s70);
    vector <int> options70;
    if (s70[7][0]!=0)
        options70.push_back(s70[7][0]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,7,0,s70)==1 && isnotincolumn(f,7,0,s70)==1 && isnotinrow(f,7,0,s70)==1)
                options70.push_back(f);
    }
    for(int it_70=0;it_70<options70.size();it_70++)
    {
    s70[7][0]=options70[it_70];
    int s71[9][9];
    if (7==0 && 1==0)
    scopy(s71,s);
    else if (1==0)
    scopy(s71,s68);
    else
    scopy(s71,s70);
    vector <int> options71;
    if (s71[7][1]!=0)
        options71.push_back(s71[7][1]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,7,1,s71)==1 && isnotincolumn(f,7,1,s71)==1 && isnotinrow(f,7,1,s71)==1)
                options71.push_back(f);
    }
    for(int it_71=0;it_71<options71.size();it_71++)
    {
    s71[7][1]=options71[it_71];
    int s72[9][9];
    if (7==0 && 2==0)
    scopy(s72,s);
    else if (2==0)
    scopy(s72,s68);
    else
    scopy(s72,s71);
    vector <int> options72;
    if (s72[7][2]!=0)
        options72.push_back(s72[7][2]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,7,2,s72)==1 && isnotincolumn(f,7,2,s72)==1 && isnotinrow(f,7,2,s72)==1)
                options72.push_back(f);
    }
    for(int it_72=0;it_72<options72.size();it_72++)
    {
    s72[7][2]=options72[it_72];
    int s73[9][9];
    if (7==0 && 3==0)
    scopy(s73,s);
    else if (3==0)
    scopy(s73,s68);
    else
    scopy(s73,s72);
    vector <int> options73;
    if (s73[7][3]!=0)
        options73.push_back(s73[7][3]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,7,3,s73)==1 && isnotincolumn(f,7,3,s73)==1 && isnotinrow(f,7,3,s73)==1)
                options73.push_back(f);
    }
    for(int it_73=0;it_73<options73.size();it_73++)
    {
    s73[7][3]=options73[it_73];
    int s74[9][9];
    if (7==0 && 4==0)
    scopy(s74,s);
    else if (4==0)
    scopy(s74,s68);
    else
    scopy(s74,s73);
    vector <int> options74;
    if (s74[7][4]!=0)
        options74.push_back(s74[7][4]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,7,4,s74)==1 && isnotincolumn(f,7,4,s74)==1 && isnotinrow(f,7,4,s74)==1)
                options74.push_back(f);
    }
    for(int it_74=0;it_74<options74.size();it_74++)
    {
    s74[7][4]=options74[it_74];
    int s75[9][9];
    if (7==0 && 5==0)
    scopy(s75,s);
    else if (5==0)
    scopy(s75,s68);
    else
    scopy(s75,s74);
    vector <int> options75;
    if (s75[7][5]!=0)
        options75.push_back(s75[7][5]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,7,5,s75)==1 && isnotincolumn(f,7,5,s75)==1 && isnotinrow(f,7,5,s75)==1)
                options75.push_back(f);
    }
    for(int it_75=0;it_75<options75.size();it_75++)
    {
    s75[7][5]=options75[it_75];
    int s76[9][9];
    if (7==0 && 6==0)
    scopy(s76,s);
    else if (6==0)
    scopy(s76,s68);
    else
    scopy(s76,s75);
    vector <int> options76;
    if (s76[7][6]!=0)
        options76.push_back(s76[7][6]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,7,6,s76)==1 && isnotincolumn(f,7,6,s76)==1 && isnotinrow(f,7,6,s76)==1)
                options76.push_back(f);
    }
    for(int it_76=0;it_76<options76.size();it_76++)
    {
    s76[7][6]=options76[it_76];
    int s77[9][9];
    if (7==0 && 7==0)
    scopy(s77,s);
    else if (7==0)
    scopy(s77,s68);
    else
    scopy(s77,s76);
    vector <int> options77;
    if (s77[7][7]!=0)
        options77.push_back(s77[7][7]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,7,7,s77)==1 && isnotincolumn(f,7,7,s77)==1 && isnotinrow(f,7,7,s77)==1)
                options77.push_back(f);
    }
    for(int it_77=0;it_77<options77.size();it_77++)
    {
    s77[7][7]=options77[it_77];
    int s78[9][9];
    if (7==0 && 8==0)
    scopy(s78,s);
    else if (8==0)
    scopy(s78,s68);
    else
    scopy(s78,s77);
    vector <int> options78;
    if (s78[7][8]!=0)
        options78.push_back(s78[7][8]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,7,8,s78)==1 && isnotincolumn(f,7,8,s78)==1 && isnotinrow(f,7,8,s78)==1)
                options78.push_back(f);
    }
    for(int it_78=0;it_78<options78.size();it_78++)
    {
    s78[7][8]=options78[it_78];
    int s80[9][9];
    if (8==0 && 0==0)
    scopy(s80,s);
    else if (0==0)
    scopy(s80,s78);
    else
    scopy(s80,s80);
    vector <int> options80;
    if (s80[8][0]!=0)
        options80.push_back(s80[8][0]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,8,0,s80)==1 && isnotincolumn(f,8,0,s80)==1 && isnotinrow(f,8,0,s80)==1)
                options80.push_back(f);
    }
    for(int it_80=0;it_80<options80.size();it_80++)
    {
    s80[8][0]=options80[it_80];
    int s81[9][9];
    if (8==0 && 1==0)
    scopy(s81,s);
    else if (1==0)
    scopy(s81,s78);
    else
    scopy(s81,s80);
    vector <int> options81;
    if (s81[8][1]!=0)
        options81.push_back(s81[8][1]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,8,1,s81)==1 && isnotincolumn(f,8,1,s81)==1 && isnotinrow(f,8,1,s81)==1)
                options81.push_back(f);
    }
    for(int it_81=0;it_81<options81.size();it_81++)
    {
    s81[8][1]=options81[it_81];
    int s82[9][9];
    if (8==0 && 2==0)
    scopy(s82,s);
    else if (2==0)
    scopy(s82,s78);
    else
    scopy(s82,s81);
    vector <int> options82;
    if (s82[8][2]!=0)
        options82.push_back(s82[8][2]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,8,2,s82)==1 && isnotincolumn(f,8,2,s82)==1 && isnotinrow(f,8,2,s82)==1)
                options82.push_back(f);
    }
    for(int it_82=0;it_82<options82.size();it_82++)
    {
    s82[8][2]=options82[it_82];
    int s83[9][9];
    if (8==0 && 3==0)
    scopy(s83,s);
    else if (3==0)
    scopy(s83,s78);
    else
    scopy(s83,s82);
    vector <int> options83;
    if (s83[8][3]!=0)
        options83.push_back(s83[8][3]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,8,3,s83)==1 && isnotincolumn(f,8,3,s83)==1 && isnotinrow(f,8,3,s83)==1)
                options83.push_back(f);
    }
    for(int it_83=0;it_83<options83.size();it_83++)
    {
    s83[8][3]=options83[it_83];
    int s84[9][9];
    if (8==0 && 4==0)
    scopy(s84,s);
    else if (4==0)
    scopy(s84,s78);
    else
    scopy(s84,s83);
    vector <int> options84;
    if (s84[8][4]!=0)
        options84.push_back(s84[8][4]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,8,4,s84)==1 && isnotincolumn(f,8,4,s84)==1 && isnotinrow(f,8,4,s84)==1)
                options84.push_back(f);
    }
    for(int it_84=0;it_84<options84.size();it_84++)
    {
    s84[8][4]=options84[it_84];
    int s85[9][9];
    if (8==0 && 5==0)
    scopy(s85,s);
    else if (5==0)
    scopy(s85,s78);
    else
    scopy(s85,s84);
    vector <int> options85;
    if (s85[8][5]!=0)
        options85.push_back(s85[8][5]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,8,5,s85)==1 && isnotincolumn(f,8,5,s85)==1 && isnotinrow(f,8,5,s85)==1)
                options85.push_back(f);
    }
    for(int it_85=0;it_85<options85.size();it_85++)
    {
    s85[8][5]=options85[it_85];
    int s86[9][9];
    if (8==0 && 6==0)
    scopy(s86,s);
    else if (6==0)
    scopy(s86,s78);
    else
    scopy(s86,s85);
    vector <int> options86;
    if (s86[8][6]!=0)
        options86.push_back(s86[8][6]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,8,6,s86)==1 && isnotincolumn(f,8,6,s86)==1 && isnotinrow(f,8,6,s86)==1)
                options86.push_back(f);
    }
    for(int it_86=0;it_86<options86.size();it_86++)
    {
    s86[8][6]=options86[it_86];
    int s87[9][9];
    if (8==0 && 7==0)
    scopy(s87,s);
    else if (7==0)
    scopy(s87,s78);
    else
    scopy(s87,s86);
    vector <int> options87;
    if (s87[8][7]!=0)
        options87.push_back(s87[8][7]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,8,7,s87)==1 && isnotincolumn(f,8,7,s87)==1 && isnotinrow(f,8,7,s87)==1)
                options87.push_back(f);
    }
    for(int it_87=0;it_87<options87.size();it_87++)
    {
    s87[8][7]=options87[it_87];
    int s88[9][9];
    if (8==0 && 8==0)
    scopy(s88,s);
    else if (8==0)
    scopy(s88,s78);
    else
    scopy(s88,s87);
    vector <int> options88;
    if (s88[8][8]!=0)
        options88.push_back(s88[8][8]);
    else
    {
        for(int f=1;f<=9;f++)
            if (isnotingrid(f,8,8,s88)==1 && isnotincolumn(f,8,8,s88)==1 && isnotinrow(f,8,8,s88)==1)
                options88.push_back(f);
    }
    for(int it_88=0;it_88<options88.size();it_88++)
    {
    s88[8][8]=options88[it_88];
		cout<<"\nSuccess!!\n\nThis is your answer\n";
		printsudoku(s88);
        return 0;

	}
    }
    }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
}

int main()
{
	int sudoku[9][9];
	take_input(sudoku);


	/*for(int i=0;i<9;i++)
	for(int j=0;j<9;j++)
	{
	if (sudoku[i][j]==0)
	checker[i][j]="Empty";
	else
	checker[i][j]="Already filled";
	}*/

	//rem and prevrem check if solo filling and rejected filling fnctions have finished filling cells and are not capable of filling any more
	int rem=90,prevrem=1;
	int bf=0;
	while(rem>0)
	{
		for(int i=0; i<9; i++)
		{
			for(int j=0; j<9; j++)
			{
			    if (sudoku[i][j]==0)
			    {
				//try to fill by solo candidate
				//cout<<"Filing using  Solo Candidate Rule...\n";
				solofill(sudoku,i,j);
				//if still not filled, try to fill by rejected candidate
				if (sudoku[i][j]==0)
				{//cout<<"Filling Using Rejected Candidate Rule\n";
				rejfill(sudoku,i,j);}
			    }
			}
		}
		prevrem=rem;
		rem=0;
		for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
		if (sudoku[i][j]==0)
		rem++;
		cout<<"\n\nThis is the Current Stage of Sudoku :\n";
		printsudoku(sudoku);
		if (prevrem==rem)
            	{//cout<<"\n\n";
		bf=1; break;}
	}


	//the variable bf tells the program if the sudoku has been completely solved using general sudoku solving algorithm or Brute Force is needed.
	if (bf==0)
	{
		cout<<"\n\n\nYour Sudoku has been solved without using Brute Force.\n This is the answer:\n";
		printsudoku(sudoku);
	}
	else
	{
		//applying brute force to solve the sudoku now
		//cout<<"Sudoku could no...";
		bruteattack(sudoku);
		//cout<<"Brute Attack has done it's work.\n\n";
		cout<<"Solved\n\n";

	}
	/*int x=0,z=0;
	while( x!=10 )
	{
	cout<<"Enter rn cn to check filling function for specific cells, enter rn=10 to quit\n";
	cin>>x>>z;
	cout<<checker[x][z]<<"\n";
	}*/

	return 0;
}


