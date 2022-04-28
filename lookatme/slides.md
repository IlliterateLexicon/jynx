---

title: Jynx
author: IlliterateLexicon
styles:
  headings:
    "1":
      prefix: " "
      suffix: " "
    "2":
      prefix: "  "
      suffix: "  "
  bullets:
    '1': 
extensions:
  - terminal

---

# Jynx
* Jynx Is a Library that makes using complex and simple terminal functions easy.

# What is Jynx
* Jynx is a collection of functions that provideds an simple interface for interaction with posix functions, advanced input, and simple escape codes

# What Does this Mean?
* It means that you can code rather simple and readable code that can produce results that would be very complex to get from scratch. 

# What Does this Mean?
* It means that you can code rather simple and readable code that can produce results that would be very complex to get from scratch. 
* Take this code for example

# What Does this Mean?
* It means that you can code rather simple and readable code that can produce results that would be very complex to get from scratch. 
* Take this code for example

```
#include <jynx/jynx.hpp>
   
int main() {
	jynx.output.clear(); //clear the terminal
	junx.output.color(0xff0000); //set color to red
	jynx.output.print("Hello Red"); //print text
	jynx.output.reset(); //reset color and attributes
}
```

# What Does this Mean?
* It means that you can code rather simple and readable code that can produce results that would be very complex to get from scratch. 
* Take this code for example

```
#include <iostream>
   
int main() {
	std::cout << "\033[2J"
	std::cout << "\033[31m";
	std::cout << "\033[31m";
	std::cout << "\033[31m";
}
```

## Lets Run That

```terminal5
bash -il 
```
