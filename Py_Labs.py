import random;
import math;

class Lesson3:
  def __init__(self):
    self.var_int = 10;
    self.var_float = 8.4;
    self.var_str = "No";
    self.execute();
  
  def execute(self):
    self.big_int = self.var_int * 3.5;
    self.var_float = self.var_float - 1;
    print("---Lesson 3---");
    print(f'Result [big_int]: {self.big_int}');
    print(f'Result [var_float - 0]: {self.var_float}');
    print(f'Result [var_int/var_float]: {self.var_int/self.var_float}');
    print(f'Result [big_int/var_float]: {self.big_int/self.var_float}');
    print(f'Result [var_str * 2 + "Yes" * 3]: {self.var_str * 2 + "Yes" * 3}');
 
class Lesson4:
  def __init__(self):
     self.var1 = random.randint(0, 200);
     self.var2 = random.uniform(0, 200);
     self.str1 = "d";
     self.str2 = "v";
     self.bool1 = self.var1 > 100 and self.var2 < 50;
     self.bool2 = self.var1 > 50 and self.var2 > -100;
     self.bool3 = self.var1 < 50 and self.var2 != 100;
     self.bool4 = self.var1 == 23 and self.var2 == 84;
     self.bool5 = self.var1 == 56 or self.var2 > 0;
     self.bool6 = self.var1 > 0 or self.var2 < 200;
     self.bool7 = self.var1 > 100 or self.var2 == 100;
     self.bool8 = self.var1 != -1 or self.var2 > 200;
     self.bool9 = self.str1 > "a" and self.str2 == "v";
     self.bool10 = self.str1 > "d" or self.str2 < "x";
     self.execute();
  def execute(self):
     print("---Lesson 4---");
     print(f'Variable 1 [INT]: {self.var1}');
     print(f'Variable 2 [FLOAT]: {self.var2}');
     print(f'Variable 3 [STRING]: {self.str1}');
     print(f'Variable 4 [STRING]: {self.str2}');
     print(f'Boolean 1 [Var1 > 100 and Var2 < 50]: {self.bool1}');
     print(f'Boolean 2 [Var1 > 50 or Var2 > -100]: {self.bool2}');
     print(f'Boolean 3 [Var1 < 50 and Var2 != 100]: {self.bool3}');
     print(f'Boolean 4 [Var1 == 23 or Var2 == 84]: {self.bool4}');
     print(f'Boolean 5 [Var1 == 56 and Var2 > 0]: {self.bool5}');
     print(f'Boolean 6 [Var1 > 0 or Var2 < 200]: {self.bool6}');
     print(f'Boolean 7 [Var1 > 100 and Var2 == 100]: {self.bool7}');
     print(f'Boolean 7 [Var1 != -1 or Var2 > 200]: {self.bool8}');
     print(f'Boolean 9 [String 1 > a and String 2 = v]: {self.bool9}');
     print(f'Boolean 10 [String 1 > d or String 2 < x]: {self.bool10}');
     
 class Lesson5:
    def __init__(self):
       self.v1 = 10;
       self.v2 = -10;
       self.bool = False;
       self.execute();
    def execute(self):
      print("---Lesson 5---")
      if (self.v1 > 0):
        print(f'Значение {self.v1} > 0');
      if (self.v2 < 0):
        print(f'Значение {self.v2} < 0');
      if (self.v1 > 0):
        print(1);
      else:
        print(-1);
      if (self.v2 < 0):
        print(1);
      else:
        print(-1);
      if (self.v1/self.v2 > 0): self.bool = True;
      else: print("Skip")
      print(f'v1/v2 > 0 | {self.bool}')
      if (self.v1 - self.v2 == 0): self.bool = True;
      else: print("Skip")
      print(f'v1 - v2 == 0 | {self.bool}')
      if (self.v1 > 0 and self.v2 < 0): self.bool = True;
      else: print("Skip")
      print(f'v1 > 0 and v2 < 0 | {self.bool}')
      
 class Lesson6:
    def __init__(self):
       self.v1 = random.randint(0, 1000);
       self.v2 = random.randint(0, 1000);
       self.execute();
    def execute(self):
       print("---Lesson 6---")
       if (self.v1 > self.v2):
          self.v3 = self.v1 - self.v2;
      elif (self.v1 < self.v2):
          self.v3 = self.v1 + self.v2;
      else:
        self.v3 = self.v1;
      print(f'Variable 3: {self.v3}');
      if (self.v1 * self.v2 > math.pow(self.v2, 2)):
        self.v3 = self.v2 * self.v1;
      elif (self.v2 / self.v1 - 1 < self.v1):
        self.v3 = self.v2;
      elif (math.sin(self.v1) > math.cos(self.v2)):
        self.v3 = math.tan(self.v1 + self.v2);
      else:
        self.v3 = math.sqrt(self.v1 - self.v2);
      print(f'Variable 3: {self.v3}');
      
  class Lesson7:
      def __init__(self):
         self.p1 = 0;
         self.p2 = 1;
         self.v = 10;
         self.l = 0;
         self.execute();
      def execute(self):
         print("---Lesson 7---")
         print(f'Число Фибоначчи: {self.p1}')
         print(f'Число Фибоначчи: {self.p2}')
         while (self.l < self.v):
           self.sum = self.p1 + self.p2
           print(f'Число Фибоначчи: {self.sum}')
           self.p1 = self.p2
           self.p2 = self.sum
           self.l = self.l + 1;
         print("---------------------")
         self.v = 14;
         self.l = 0;
         self.p1 = 3;
         self.p2 = 5
         print(f'Число Фибоначчи: {self.p1}')
         print(f'Число Фибоначчи: {self.p2}')
         while (self.l < self.v):
           self.sum = self.p1 + self.p2
           print(f'Число Фибоначчи: {self.sum}')
           self.p1 = self.p2
           self.p2 = self.sum
           self.l = self.l + 1;
         print("---------------------")
         self.s = 1;
         self.e = 21;
         while (self.s < self.e):
            if (self.s % 2 == 0): print(f'Четное число: {self.s}')
            self.s = self.s + 1;
         print("---------------------")
         self.d = -1;
         self.k = -22;
         while (self.d > self.k):
           if (self.d % 3 == 0): print(f'Число {self.d}')
           self.d = self.d - 1;
         print("---------------------")
         self.o = 0;
         self.z = 10;
         while (self.o < self.z):
           print(f'Sqr {math.pow(self.o, 2)}')
           self.o = self.o + 1;
  class Lesson8:
    def __init__(self):
       self.name = "";
       self.old = 0;
       self.live = "";
       self.x = 4 * 100 - 54;
       self.answer = 0;
       self.execute();
    def execute(self):
       print("---Lesson 8---");
       self.name = input("What is your name? ");
       self.old = int(input("How old are you? "));
       self.live = input("Where are you live? ");
       print(f'This is {self.name}\n'
         f'It is {self.old}\n'
         f'He live in {self.live}');
      self.answer = int(input("4 * 100 - 54 = "));
      if (self.answer == self.x):
         print(f'Вы ввели правильный ответ, поздравляем!');
      else: print(f'Вы ввели неправильный ответ, попробуйте в следующий раз!');
      print("Попробуем другой метод:");
      self.answer = int(input("4 * 100 - 54 = "));
      while (self.x != self.answer):
         print("Вы допустили ошибку, попробуйте еще раз:");
         self.answer = int(input("4 * 100 - 54 = "));
      if (self.answer == self.x):
         print(f'Вы ввели правильный ответ, поздравляем!');
         
  class Lesson9():
     def __init__(self):
         self.s = "0JLRgdC1INC30L3QsNGH0LXQvdC40Y8g0LIgUHl0aG9uINC90LDQt9GL0LLQsNGO0YLRgdGPIMKr0L7QsdGK0LXQutGC0LDQvNC4wrs=";
         self.s2 = "RGVjb2RlIGFuZCBFbmNvZGU=";
         self.i = int(len(self.s2) / 2 - 2);
         self.v = int(len(self.s2) / 2 + 2);
         self.execute()
      def execute(self):
         print("---Lesson 9---");
         print(f'Первый символ: {self.s[0]}\n'
             f'Последний символ: {self.s[-1]}\n'
             f'Третий с начала: {self.s[2]}\n'
             f'Третий с конца: {self.s[-3]}\n'
             f'Длина строки: {len(self.s)}')
         print(f'Первые 8 символов: {self.s2[0:7]}\n'
             f'Четыре символа из центра строки: {self.s2[self.i:self.v]}\n'
             f'Символы с индексами кратными трем: {self.s2[::3]}')
             
  class Lesson10():
      def __init__(self):
         self.mainID = [22149, 8460, 17172, 16206, 11884, 9206];
         self.parentID = [21738, 5406, 1854, 21739, 13089, 17172];
         self.execute();
      def execute(self):
         print("---Lesson 10---");
         print(f'Второй элемент: {self.mainID[1]}');
         self.parentID[-1] = 42323;
         print(f'Второй список: {self.parentID}');
         self.ID = self.mainID + self.parentID;
         print(f'Новый список: {self.ID}');
         self.ID = self.ID[5::];
         print(f'Срез: {self.ID}');
         self.ID = self.ID[2:3] + [1, 0];
         print(f'Список с новыми элементами: {self.ID}');
         
class Lesson11():
    def __init__(self):
      self.school = {
         1: 20,
         2: 21,
         3: 15,
         4: 18,
         5: 31,
         6: 10,
         7: 12,
         8: 15,
         9: 19,
         10: 18
      }
      self.execute();
    def execute(self):
       print("---Lesson 11---");
       print(f'В 6 классе {self.school[4]} учеников.')
       self.school[2] = 23;
       self.school[7] = 41;
       self.school[11] = 20;
       self.school[12] = 21;
       self.school[13] = 10;
       del(self.school[10]);
       print(f'{self.school}')
       
class Lesson12():
  def __init__(self):
     self.list = ['hi', 'hello', 'good morning', 'how do you do'];
     self.ID = [22150, 8460, 17172, 16206, 11884, 9206, 21739, 5406, 1854, 21739, 13089, 17172, 21479];
     self.iter = 1;
     self.execute();
  def execute(self):
    print("---Lesson 13---");
    for self.str in self.list:
      print(f'Key: {self.str}')
    for self.str in self.list:
      for self.char in self.str:
        print(self.char, end="-")
      print();
    for self.id in self.ID:
      self.ID[self.iter] = float(self.id)
      self.iter = self.iter + 2;
    print(f'Список: {self.ID}')
    
class Lesson13():
  def __init__(self):
     print("---Lesson 14---");
     self.x = int(input("Число 2: "));
     self.y = int(input("Число 3: "));
     self.z = int(input("Число 4: "));
  def execute(self):
     print(f'Сумма: {self.x + self.y + self.z}')
     self.call()
  def call(self):
    print("Вторая функция.")
    
    
    
Lesson3();
Lesson4();
Lesson5();
Lesson6();
Lesson7();
Lesson8();
Lesson9();
Lesson10();
Lesson11();
Lesson12();
Lesson13().execute();
