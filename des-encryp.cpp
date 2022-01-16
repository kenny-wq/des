#include<bits/stdc++.h>
using namespace std;

int initial_permutation[64] = { 
	58,50,42,34,26,18,10,2, 
	60,52,44,36,28,20,12,4, 
	62,54,46,38,30,22,14,6, 
	64,56,48,40,32,24,16,8, 
	57,49,41,33,25,17,9,1, 
	59,51,43,35,27,19,11,3, 
	61,53,45,37,29,21,13,5, 
	63,55,47,39,31,23,15,7 
	}; 
int inverse_permutation[64]= { 
	40,8,48,16,56,24,64,32, 
	39,7,47,15,55,23,63,31, 
	38,6,46,14,54,22,62,30, 
	37,5,45,13,53,21,61,29, 
	36,4,44,12,52,20,60,28, 
	35,3,43,11,51,19,59,27, 
	34,2,42,10,50,18,58,26, 
	33,1,41,9,49,17,57,25 
};
// The expansion table
int expansion_table[48] = { 
	32,1,2,3,4,5,4,5, 
	6,7,8,9,8,9,10,11, 
	12,13,12,13,14,15,16,17, 
	16,17,18,19,20,21,20,21, 
	22,23,24,25,24,25,26,27, 
	28,29,28,29,30,31,32,1 
	}; 
// The substitution boxes. The should contain values
// from 0 to 15 in any order.
int substition_boxes[8][4][16]=  
	{{ 
	    4,14,13,1,2,15,11,8,3,10,6,12,5,9,0,7, 
	    0,15,7,4,14,2,13,1,10,6,12,11,9,5,8,3, 
	    4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0, 
	    13,12,8,2,4,9,1,7,5,11,3,14,10,0,6,15
	}, 
	{ 
	    15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10, 
	    3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5, 
	    0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15, 
	    13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9 
	}, 
	{ 
	    10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8, 
	    13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1, 
	    13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7, 
	    1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12 
	}, 
	{ 
	    7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15, 
	    13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9, 
	    10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4, 
	    3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14 
	}, 
	{ 
	    2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9, 
	    14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6, 
	    4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14, 
	    11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3 
	}, 
	{ 
	    12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11, 
	    10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8, 
	    9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6, 
	    4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13 
	}, 
	{ 
	    4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1, 
	    13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6, 
	    1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2, 
	    6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12 
	}, 
	{ 
	    13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7, 
	    1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2, 
	    7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8, 
	    2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11 
	}};
// The permutation table
int permutation_tab[32] = { 
	16,7,20,21,29,12,28,17, 
	1,15,23,26,5,18,31,10, 
	2,8,24,14,32,27,3,9,
	19,13,30,6,22,11,4,25 
	}; 
	// The inverse permutation table

int pc1[56] = {
	57,49,41,33,25,17,9, 
	1,58,50,42,34,26,18, 
	10,2,59,51,43,35,27, 
	19,11,3,60,52,44,36,		 
	63,55,47,39,31,23,15, 
	7,62,54,46,38,30,22, 
	14,6,61,53,45,37,29, 
	21,13,5,28,20,12,4 
	};
// The PC2 table
int pc2[48] = { 
	14,17,11,24,1,5, 
	3,28,15,6,21,10, 
	23,19,12,4,26,8, 
	16,7,27,20,13,2, 
	41,52,31,37,47,55, 
	30,40,51,45,33,48, 
	44,49,39,56,34,53, 
	46,42,50,36,29,32 
	}; 
	
vector<int> shift_schedule = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

string initPer(string bit){   //64 -> 64
	string res = "";
	for(int i=0;i<64;i++){
		res+=bit[initial_permutation[i]-1];
	}
	return res;
}

string pc1Permutation(string bit){   //64->56
	string res = "";
	for(int i=0;i<56;i++){
		res+=bit[pc1[i]-1];
	}
	return res;
}

string pc2Permutation(string bit){        //56->48
	string res = "";
	for(int i=0;i<48;i++){
		res += bit[pc2[i]-1];
	}
	return res;    
}

string shift_left(string bit,int round){   //28->28
	int times = shift_schedule[round];
	string temp = bit;
	string empty = "";
	for(int i=0;i<times;i++){
		for(int j=1;j<28;j++){
			empty+=temp[j];
		}
		empty+=temp[0];
		temp = empty;
		empty = "";
	}
	return temp;   
}

vector<string> round_key;

void generateKey(string bit){                //56
	string temp = bit;
	string left = temp.substr(0,28);
	string right = temp.substr(28,28);

	for(int i=0;i<16;i++){
		string left_shift = shift_left(left,i);
		left = left_shift;
		string right_shift = shift_left(right,i);
		right = right_shift;

		string this_round_bitset = "";
		this_round_bitset+=left;
		this_round_bitset+=right;
		
		string this_round_key = pc2Permutation(this_round_bitset);
		round_key.push_back(this_round_key);
	}             
}

string expand(string bit){
	string temp = "";
	for(int i=0;i<48;i++){
		temp += bit[expansion_table[i]-1];
	}
	return temp;             //32->48
}
int binary_to_dec(string s){
	int res = 0;
	int n = s.size();
	for(int i=n-1;i>=0;i--){
        if(s[i]=='1'){
            res+=pow(2,n-1-i);
        }
	}
	return res;
}

string dec_to_binary(int n){
	string res = "";
	while(n>0){
		if(n%2==1){
			res = "1"+res;
		}
		else{
			res = "0"+res;
		}
		n/=2;
	}
	int len = res.size();
	if(len<4){
		for(int i=0;i<4-len;i++){
			res = "0"+res;
		}
	}
	return res;
}
string dec_to_binary_eight(int n){
    string res = "";
	while(n>0){
		if(n%2==1){
			res = "1"+res;
		}
		else{
			res = "0"+res;
		}
		n/=2;
	}
	int len = res.size();
	if(len<8){
		for(int i=0;i<8-len;i++){
			res = "0"+res;
		}
	}
	return res;
}
string sbox(string bit){
	string temp = bit;
	string final = "";
	for(int i=0;i<8;i++){
		string this_round = temp.substr(i*6,6);
		string ro = "";
		ro+=this_round[0];
		ro+=this_round[5];
		int row = binary_to_dec(ro);
		string col = this_round.substr(1,4);
		int column = binary_to_dec(col);

		int result = substition_boxes[i][row][column];

		string result_string = dec_to_binary(result);
		final += result_string;
	}
	return final;                //48->32
}

string Xor(string a,string b){
	string res = "";
	for(int i=0;i<a.size();i++){
		if(a[i]=='0'&&b[i]=='0'){
			res += '0';
		}
		else if(a[i]=='0'&&b[i]=='1'){
			res += '1';
		}
		else if(a[i]=='1'&&b[i]=='0'){
			res += '1';
		}
		else if(a[i]=='1'&&b[i]=='1'){
			res += '0';
		}
	}
	return res;
}

string single_round(string bit,string round_key){
	string temp = bit;
	string left = temp.substr(0,32);
	string right = temp.substr(32,32);

	string right_expand = expand(right);
	right_expand = Xor(round_key,right_expand);

	string right_sbox = sbox(right_expand);

	string right_pbox_permutation = "";
	for(int i=0;i<32;i++){
		right_pbox_permutation += right_sbox[permutation_tab[i]-1];
	}
	right_pbox_permutation = Xor(left,right_pbox_permutation);
	string res = "";
	res+= right;
	res+=right_pbox_permutation;

	return res;           //64->64  round_key 48
}

string sixteen_round(string bit){
	string temp = bit;
	for(int i=0;i<16;i++){
		temp = single_round(temp,round_key[i]);
	}
	return temp;              //64->64
}

string deal_with_final(string final){
	string temp = final;
	string left = temp.substr(0,32);
	string right = temp.substr(32,32);

	string res = "";
	res+=right;
	res+=left;

	string final_swap = res;

	string final_permutation = "";
	for(int i=0;i<64;i++){
		final_permutation += final_swap[inverse_permutation[i]-1];
	}
	return final_permutation;       //64->64
}
void str_to_binary(string& s){
    string res = "";
    for(int i=0;i<s.size();i++){
        int c = s[i];
        res+=dec_to_binary_eight(c);
    }
    s = res;
}

vector<int> stringcipher_to_intcipher(string s){
	vector<string> eight_bit;
	for(int i=0;i<64;i+=4){
		string t = s.substr(i,4);
		eight_bit.push_back(t);
	}
	vector<int> res;
	for(int i=0;i<eight_bit.size();i++){
		int k = binary_to_dec(eight_bit[i]);
		res.push_back(k);
	}
	return res;
}
int main(){
	string key;
	string plaintext;

	getline(cin,key);
	getline(cin,plaintext);

	str_to_binary(key);
	str_to_binary(plaintext);

	string initial_plain = initPer(plaintext);
	string pc1_key = pc1Permutation(key);
	
	generateKey(pc1_key);

	string final = sixteen_round(initial_plain);
	string ciphertext = deal_with_final(final);

	vector<int> ciphertext_decimal = stringcipher_to_intcipher(ciphertext);
	for(int i=0;i<ciphertext_decimal.size();i++){
		cout<<hex<<ciphertext_decimal[i];
	}
	cout<<endl;
	return 0;
}