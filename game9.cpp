#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
	cout<<"____________________________________________________"<<endl;
    cout<<endl<<"ahlan ya user ya habibi ...\n\n";
		
    string mode, text, tmp;
    int i , j , k , l , key , jump1 , jump2 ;
		
    cout<<"What do you like to do today?\n  1- Cipher a message\n  2- Decipher a message\n  3- End\n";
		
    cin>>mode; //choosing mode
    while ( mode!="1" && mode!="2" && mode!="3" ) {
    	cout<<"only choose 1, 2 or 3\n";
    	cin>>mode;} 
    	
    if (mode=="3") { //ending program
    	cout<<"see you...";
    	return 0;}
    	
    cout<<"Enter the text : \n   "; //getting the text
    cin.get() ;
    getline(cin,text) ;
    for ( i = 0 ; i<text.length() ; i++ ) {
    	if ( text[i]==' ' ) text.erase(i,1); } 
    
    for ( i=0 ; i<text.length() ; i++ ) { //converting all letters to lower case
    	if (text[i]>='A' && text[i]<='Z' ) {
		text[i]=text[i]+32;} }
			
    cout<<"Enter the key : ";
    while ( 1 ) { //checking the key
    	cin>>key;
    	if ( cin.fail() || key<=1 ) {
    		cout << "invalid key , enter another one : ";
    		cin.clear() ;
    		cin.ignore(numeric_limits<streamsize>::max(), '\n') ;
    		continue; }
    	break; }
    	
    tmp=text;
    jump1=2*key-2;
    jump2=0;
    l=0;
    	
    if (mode=="1") { //Encryption method ****
    	for ( i=0 ; i<key ; i++) {
    		if (i==0 || i==(key-1) ) {
    			j=i;
    			while ( j<text.length() ) {
    					tmp[l]=text[j] ;
    					j+=2*key-2;
    					l+=1;} }
    		else if ( i>0 & i<key-1 ) {
    			jump1-=2;
    			jump2+=2;
    			k=0;
    			j=i;
    			while ( j<text.length() ) {
    				if ( k%2==0 ) {
    					tmp[l]=text[j] ;
    					j+=jump1;}
    				if ( k%2==1 ) {
    					tmp[l]=text[j] ;
    					j+=jump2;}
    				k+=1;
    				l+=1;} } } //end while , elif , for
    	cout<<endl<<"The encrypted text is : << "<<tmp<<" >>"<<endl;}
    	
    else if (mode=="2") { //Decryption method ****
    	for ( i=0 ; i<key ; i++) {
    		if (i==0 || i==(key-1) ) {
    			j=i;
    			while ( j<text.length() ) {
    					tmp[j]=text[l];
    					j+=2*key-2;
    					l+=1;} }
    		else if ( i>0 & i<key-1 ) {
    			jump1-=2;
    			jump2+=2;
    			k=0;
    			j=i;
    			while ( j<text.length() ) {
    				if ( k%2==0 ) {
    					tmp[j]=text[l] ;
    					j+=jump1;}
    				if ( k%2==1 ) {
    					tmp[j]=text[l] ;
    					j+=jump2;}
    				k+=1;
    				l+=1;} } } //end while , elif , for
    	cout<<endl<<"The decrypted text is : << "<<tmp<<" >>"<<endl;}
    	
    main () ;
} 
    		
