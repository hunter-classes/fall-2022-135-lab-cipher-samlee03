#include <iostream>
#include "funcs.h"
#include "cmath"
// add functions here
// from caesar cipher
char shiftChar(char c, int rshift){
  char newChar = c;
  if (c >= 65 && c <= 90){
    int value = c - 65 + rshift;
    value = value % 26;
    newChar = value + 65;
  } else if (c >= 97 && c <= 122){
    int value = c - 97 + rshift;
    value = value % 26;
    newChar = value + 97;
  }
  return newChar;
}
std::string encryptCaesar(std::string plaintext, int rshift){
  std::string newString = "";
  for (int i = 0; i < plaintext.length(); i++){
    newString += shiftChar(plaintext[i], rshift);
  }
  return newString;
}

void calculate_freq(double frequency_encrypted[], std::string str){
  int count = 0;
  for (int i = 0; i < str.length(); i++){
    if (str[i] == 'a'){
      frequency_encrypted[0]++;
    } else if (str[i] == 'b'){
      frequency_encrypted[1]++;
    } else if (str[i] == 'c'){
      frequency_encrypted[2]++;
    } else if (str[i] == 'd'){
      frequency_encrypted[3]++;
    } else if (str[i] == 'e'){
      frequency_encrypted[4]++;
    } else if (str[i] == 'f'){
      frequency_encrypted[5]++;
    } else if (str[i] == 'g'){
      frequency_encrypted[6]++;
    } else if (str[i] == 'h'){
      frequency_encrypted[7]++;
    } else if (str[i] == 'i'){
      frequency_encrypted[8]++;
    } else if (str[i] == 'j'){
      frequency_encrypted[9]++;
    } else if (str[i] == 'k'){
      frequency_encrypted[10]++;
    } else if (str[i] == 'l'){
      frequency_encrypted[11]++;
    } else if (str[i] == 'm'){
      frequency_encrypted[12]++;
    } else if (str[i] == 'n'){
      frequency_encrypted[13]++;
    } else if (str[i] == 'o'){
      frequency_encrypted[14]++;
    } else if (str[i] == 'p'){
      frequency_encrypted[15]++;
    } else if (str[i] == 'q'){
      frequency_encrypted[16]++;
    } else if (str[i] == 'r'){
      frequency_encrypted[17];
    } else if (str[i] == 's'){
      frequency_encrypted[18]++;
    } else if (str[i] == 't'){
      frequency_encrypted[19]++;
    } else if (str[i] == 'u'){
      frequency_encrypted[20]++;
    } else if (str[i] == 'v'){
      frequency_encrypted[21]++;
    } else if (str[i] == 'w'){
      frequency_encrypted[22]++;
    } else if (str[i] == 'x'){
      frequency_encrypted[23]++;
    } else if (str[i] == 'y'){
      frequency_encrypted[24]++;
    } else if (str[i] == 'z'){
      frequency_encrypted[25]++;
    }
  }
  for (int i = 0; i < 26; i++){
    frequency_encrypted[i] = (frequency_encrypted[i] / str.length());
  }
}
std::string solve(std::string encrypted_string){
  double frequency_encrypted[26];
  double frequency_english[26] = {0.084966, 0.020720, 0.045388, 0.033844, 0.111607, 0.018121, 0.024705, 0.030034, 0.075448,0.001965, 0.011016, 0.054893, 0.030129, 0.066544, 0.071635, 0.031671, 0.001962, 0.075809, 0.057351, 0.069509, 0.036308,0.010074, 0.012899, 0.002902, 0.017779, 0.002722};
  double distances[26];
  double sum;
  std::string str = encrypted_string;
  // rotate
  // calc freq each time
  // perform distance formula  
  for (int i = 0; i < 26; i++){ // rotation
    if (i != 0){
      str = encryptCaesar(str, 1);
    }
    //std::cout << str << std::endl;
    //reset and calc freq
    for (int j = 0; j < 26; j++){ // reset freq_encrypt array
      frequency_encrypted[j] = 0;
    }
    calculate_freq(frequency_encrypted, str);
    //print freq array
    for (int j = 0; j<26;j++){
      //std::cout << frequency_encrypted[j] << " ";
    }
    //std::cout << "\n";
    //perform distance formula
    double sum = 0;
    
    for (int k = 0; k < 26; k++){
      //std::cout <<  frequency_encrypted[k] << " " << frequency_english[k] << std::endl;
      double difference = frequency_encrypted[k] - frequency_english[k];
      //std::cout << "pow " << pow(difference, 2);
      //std::cout << difference << std::endl;
      sum += difference * difference;
      
      //std::cout << "Sum: " << sum;
      
    }
    distances[i] = sqrt(sum);
    //std::cout << distances[i] << " ";
  }
  //check for minimum
  int minimum = 0;
  double smallest_dist = distances[0];
  for (int i = 0; i < 26; i++){
    if (distances[i] < smallest_dist){
      smallest_dist = distances[i];
      minimum = i;
    }
  }
  //std::cout << "The minimum is " << minimum << " shift" << std::endl; 
  
  //std::cout << sum;
  return encryptCaesar(encrypted_string, minimum);
}
