
// Implementing KMP algorithm

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void combine_two_strings(char s1[], int M, char s2[], int N, char s[]) {
     int i,j;
    // put s1 in s
    for(i=0,j=0;i<M;i++) {
        s[j++] = s1[i];
    }
    // put $ in s
    s[j++] = ' ';
    //put s2 in s
    for(i=0;i<N;i++) {
        s[j++] = s2[i];
    }
}

void compute_prefix_function(char s[], char lps[], int len) {
    int border =0;
    lps[0] = 0;
    int i;
    for(i=1; i<len; i++) {
		//if(s[i]==' ')
			//lps[i]=0;
        while(border >0 && s[i] != s[border]) {
            border = lps[border-1];
        }
        if(s[i] == s[border]) {
            border = border + 1;
        }
        else {
            border = 0;
        }
        lps[i] = border;
    }
}

int kmp(char pattern[],int M, char text[], int N) {
    char s[M+N+1];
    char lps[M+N+1];
    int i, count=0;
    // concatenate pattern and text in s, with a $ in between
    combine_two_strings(pattern,M, text, N, s);
    // compute prefix function of s
    compute_prefix_function(s, lps, M+N+1);
    // start from text position in lps and check if lps[i] == M. ==> print i-2M
    for(i=M+1; i< M+N+1; i++) {
            if(lps[i] == M)
			{
				printf("\nX=%d (Pattern occurs at position %d in text)\n",i+1-2*M, i+1-2*M );
				count++;
			}
    }
	if(count == 0)
		printf("\nX=0 (Pattern not found)\n");
}

int main() {
    int M, N;
    
	printf("Enter the length of text : ");
    scanf("%d", &N);
    if(N<1 || N>500)
    {
        printf("Length of the Text should be in the range of 1 to 500\n");
    }
    else
    {
        printf("\nEnter length of pattern : ");
        scanf(" %d", &M);
        if(M<1 || M>500)
        {
            printf("Length of the Pattern should be in the range of 1 to 500\n");
        }
        else
        {
	        char text[N];
            printf("\nEnter the text :");
	        scanf(" %[A-Za-z ]s", text);
	
	        char pattern[M];
            printf("\nEnter the pattern :");
	        scanf(" %[A-Za-z ]s", pattern);
	
            kmp(pattern, M, text, N);
            getch();
            return 0;
        }
    }
}