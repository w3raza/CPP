#include <iostream>

#ifndef Filters_h
void cat(char** argv);
int wc_lines(char** argv);
int wc_char(char** argv);
int wc_char(char* argv);
int wc_words(char** argv);
char** tail(int val, char** argv);
char** head(int val, char** argv);
void clear(char** buf);
char** uniq(char** argv);
#endif

#ifndef FILTERS_H
#define FILTERS_H

void cat(char** argv){
  for (int i = 0; argv[i] != nullptr; i++) {
    std::cout << argv[i] << std::endl;
  }
}

int wc_lines(char** argv){
    int counter = 0;
    for (int i = 0; argv[i] != nullptr; i++) {
        counter++;
    }

    return counter;
}

int wc_char(char** argv){
    int counter = 0;
    for (int i = 0; argv[i] != nullptr; i++) {
        counter += wc_char(argv[i]);
    }

    return counter;
}

int wc_char(char* argv){
    int counter = 0;
    if(argv != nullptr){
        for(int j =0; argv[j] != '\0'; j++){
            counter++;
        }
    }
    return counter;
}

int wc_words(char** argv){
    int counter = 0;
    for (int i = 0; argv[i] != nullptr; i++) {
        int j = 0;
        while(argv[i][j] != '\0'){
            if(argv[i][j] == '_'){
                counter++;
            }
            j++;
        }
        counter++;
    }

    return counter;
}

char** tail(int val, char** argv){
    int total_lines = wc_lines(argv);
    int start = total_lines - val;
    start = start > 0 ? start : 0;

    char** output = new char*[total_lines - start + 1];

    for(int i = start, j = 0; i < total_lines; i++, j++){
        output[j] = argv[i];
    }
    output[total_lines] = nullptr;

    return output;
}

char** head(int val, char** argv){
    int total_lines = wc_lines(argv);
    int end = val;
    end = total_lines - val > 0 ? end : total_lines;

    char** output = new char*[end + 1];

    for(int i = 0; i < end; i++){
        output[i] = argv[i];
    }
    output[end + 1] = nullptr;

    return output;
}

void clear(char** buf){
    delete[] buf;
}

char** uniq(char** argv) {
  int total_lines = wc_lines(argv);
  char** output = new char*[total_lines + 1];
  int output_size = 0;
  output[output_size++] = argv[0];

  for (int i = 1; argv[i] != nullptr; i++) {
    if (strcmp(argv[i], argv[i-1]) != 0) {
      output[output_size++] = argv[i];
    }
  }
  output[output_size] = nullptr;
  return output;
}

#endif /* FILTERS_H */