/* C program to implement Railway Route Optimisation */
#include<stdio.h>
#define inf 9999
int a[40][40],x,y;
int length[40],z,j,c=0,f=0,temp[40];
//Station names module
char b[40][15]={"Adilabad","Anathapur","Ankapalle","Araku","Bhimavaram","Chittor","Cuddapah","Dornakal","Dharmavaram","Eluru","Guntur","Gudur","Guntakal","Hyderabad","Kakinada","Kazipet","Kavali","Khammam","Kurnool","Machilipatnam","Mahbubnagar","Medak","Nalgonda","Narsapur","Nellore","Nizamabad","Ongole","Rajahmundry","Renigunta","Repalle","Srikakulam","Tanuku","Tenali","Tirupathi","Tuni","Vikarabad","Vijayawada","Visakhapatnam","Vijayanagaram","Warangal"};;
main()
{
int i,v1,v2,lcost,choice;
int dij(int[][j],int,int);
for(x=0;x<40;x++)
for(y=0;y<40;y++)
//Railway distances data module
{
a[x][y]=0;
a[8][1]=33;
a[8][5]=228;
a[12][1]=86;
a[12][6]=184;
a[15][13]=141;
a[17][7]=23;
a[18][10]=333;
a[18][12]=123;
a[20][13]=91;
a[20][18]=102;
a[21][13]=77;
a[22][10]=172;
a[22][13]=92;
a[22][15]=137;
a[23][4]=32;
a[24][11]=38;
a[24][16]=51;
a[25][0]=251;
a[25][21]=70;
a[26][16]=66;
a[26][24]=118;
a[27][14]=64;
a[28][11]=83;
a[31][9]=61;
a[31][27]=39;
a[32][10]=31;
a[32][29]=34;
a[33][5]=59;
a[33][7]=270;
a[33][28]=10;
a[34][2]=64;
a[34][14]=54;
a[35][13]=73;
a[36][4]=107;
a[36][9]=52;
a[36][10]=31;
a[36][19]=63;
a[36][32]=55;
a[37][2]=32;
a[37][3]=129;
a[37][36]=46;
a[38][30]=57;
a[38][37]=46;
a[39][7]=101;
a[39][15]=10;
a[39][0]=218;
a[39][7]=85;
for(x=0;x<40;x++)
for(y=0;y<40;y++)
if(a[x][y]!=0)
a[y][x]=a[x][y];
}
printf("\t\t\t\t\t\tRailway Route Optimisation\n\n\n\n\n\n");
			printf("\n 1.) Adilabad        2.) Ananthapur     3.) Anakapalle        4.) Araku             5.) Bhimavaram");
			printf("\n 6.) Chittor         7.) Cuddapah       8.) Dornakal          9.) Dharmavaram      10.) Eluru");
			printf("\n11.) Guntur         12.) Gudur         13.) Guntakal         14.) Hyderabad        15.) Kakinada");
			printf("\n16.) Kazipet        17.) Kavali        18.) Khammam          19.) Kurnool          20.) Machilipatnam");
			printf("\n21.) Mahbubnagar    22.) Medak         23.) Nalgonda         24.) Narsapur         25.) Nellore");
			printf("\n26.) Nizamabad      27.) Ongole        28.) Rajahmundry      29.) Renigunta        30.) Repalle");
			printf("\n31.) Srikakulam     32.) Tanuku        33.) Tenali           34.) Tirupathi        35.) Tuni");
			printf("\n36.) Vikarabad      37.) Vijayawada    38.) Visakhapatnam    39.) Vijayanagaram    40.) Warangal");
			printf("\n\n\nEnter the source and destination options given above.");
			printf("\nSource:");
			scanf("%d",&v1);
			printf("Destination:");
			scanf("%d",&v2);
  			dij(a,v1-1,v2-1);
			printf("\nThe shortest distance between source and destination is:%d",length[z]);
		    printf("\nThe approximate time of journey is %.3f",(float)(length[z])/(float)(60));

}
/*Calculating and printing the shortest distance between source and destination*/
int dij(int a[40][40],int v1,int v2)
{
	int set[40],path[40],i,s,tmp;
	s=v1;
	z=v2;
	int srch_min(int[],int[]);
	for(i=0;i<40;i++)
	set[i]=0;
	for(i=0;i<40;i++)
	{
		if(a[s][i]==0)
		{
			length[i]=inf;
			path[i]=0;/*Empty path*/
		}
		else
		{
			length[i]=a[s][i];
			path[i]=s;/*s is immediate predecessor of i*/
		}
	}
	set[s]=1;/*s is included in the set*/
	length[s]=0;/*s is implicitly enumerated with length as 0*/
	while(set[z]!=1)
	{
		j=srch_min(length,set);/*Select a vertex j with minimum label such that it is not included in the set[]*/
		set[j]=1;/*Vertex j is included in the set[]*/
		for(i=0;i<40;i++)
		{
			if(set[i]!=1)
			{
				if(a[i][j]!=0)
				{
					if(length[j]+a[i][j]<length[i])/*When exsisting label is not minimum only then replacement is done*/
						{
							length[i]=length[j]+a[i][j];
							path[i]=j;
						}
				}
			}
		}
	}z                        //here set is used for traversing the node and path is used for node indiuces values(0 to 39)
	j=0;
	i=z;
	while(i!=s)
	{
		tmp=path[i];
		temp[j]=tmp;
		i=tmp;
		j++;
		c++;
	}
    for(j=c-1;j>=0;j--)
			{
				printf("%s->",b[temp[j]]);/*Print the shortest path*/
				if(temp[j]==z)
				f=1;
			}
			if(f!=1)
			printf("%s",b[z]);

}
/*This function will return a vertex with minimum label such that it is not included in set[]*/
int srch_min(int length[],int set[])
{
	int min,i,min_index;
	min=99999,min_index;
	for(i=1;i<40;i++)
	{
		if(set[i]!=1)
		{
			if(length[i]<min)
			{
				min=length[i];
				min_index=i;
			}
		}
	}
	return 	min_index;
}
