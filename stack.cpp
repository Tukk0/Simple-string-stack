#include <cstring>
#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

void double_stack(int& length, int size, char**& stack) {
  length *= 2;
  char** temp = new char*[length];
  for (int i = 0; i < size; i++) {
    temp[i] = new char[strlen(stack[i]) + 1];
    memcpy(temp[i], stack[i], strlen(stack[i]) + 1);
    delete[] stack[i];
  }
  delete[] stack;
  stack = temp;
}

void divide_stack(int& length, int size, char**& stack) {
  if (length != 1) {
    length /= 2;
  }
  char** temp = new char*[length];
  for (int i = 0; i < size; i++) {
    temp[i] = new char[strlen(stack[i]) + 1];
    memcpy(temp[i], stack[i], strlen(stack[i]) + 1);
    delete[] stack[i];
  }
  delete[] stack;
  stack = temp;
}

void push(int& length, int& size, char**& stack, char* inputstring) {
  if (size == length) {
    double_stack(length, size, stack);
  }
  stack[size] = new char[strlen(inputstring) + 1];
  memset(stack[size], 0, strlen(inputstring) + 1);
  memcpy(stack[size], inputstring, strlen(inputstring) + 1);
  ++size;
}

void back(int size, char**& stack) {
  if (size == 0) {
    cout << "error" << '\n';
    return;
  }
  cout << stack[size - 1] << '\n';
}

void pop(int& length, int& size, char**& stack) {
  if (size == 0) {
    cout << "error" << '\n';
    return;
  }
  --size;
  cout << stack[size] << '\n';
  delete[] stack[size];
  if (size * 4 <= length) {
    divide_stack(length, size, stack);
  }
}

void clear(int& length, int& size, char**& stack) {
  if (size != 0) {
    for (int i = 0; i < size; i++) {
      delete[] stack[i];
    }
    delete[] stack;
    stack = new char*[1];
    size = 0;
  }
  length = 1;
  cout << "ok" << '\n';
}

void double_str(int& len, int size, char*& string) {
  len *= 2;
  char* temp = new char[len];
  memcpy(temp, string, size);
  delete[] string;
  string = temp;
}

void inputs(char*& inp) {
  int len = 1;
  int size = 0;
  char ch;
  cin.get(ch);
  while (!isspace(ch) && !cin.eof()) {
    if (len == size) {
      double_str(len, size, inp);
    }
    inp[size] = ch;
    ++size;
    cin.get(ch);
  }
  if (len == size) {
    double_str(len, size, inp);
  }
  inp[size] = '\0';
}

int main() {
  char** stack = new char*[1];
  int size = 0;
  int length = 1;
  char* input = new char[10];
  while (1 == 1) {
    if (scanf("%s", input)) {
      if (strcmp(input, "push") == 0) {
        cin.ignore();
        char* input_string = new char[1];
        inputs(input_string);
        push(length, size, stack, input_string);
        cout << "ok" << '\n';
        delete[] input_string;
        continue;
      }
      if (strcmp(input, "pop") == 0) {
        pop(length, size, stack);
        continue;
      }
      if (strcmp(input, "back") == 0) {
        back(size, stack);
        continue;
      }
      if (strcmp(input, "size") == 0) {
        cout << size << '\n';
        continue;
      }
      if (strcmp(input, "clear") == 0) {
        clear(length, size, stack);
        continue;
      }
      if (strcmp(input, "exit") == 0) {
        break;
      }
    }
  }
  cout << "bye" << '\n';
  delete[] input;
  for (int i = 0; i < size; i++) {
    delete[] stack[i];
  }
  delete[] stack;
  return 0;
}
