## cpp_module_00 - Warlock Class

### 🚀 Objective

This exercise introduces basic object-oriented programming in C++.  
You must implement a `Warlock` class that adheres to the **Coplien form**, ensures **encapsulation**, and restricts **copy operations**. The Warlock can introduce himself and has a name and a title.

---

### 📦 Files to submit

- `Warlock.hpp`
- `Warlock.cpp`

---

### 📚 Concepts used

- Coplien form (Canonical form in C++)
- Constructors & destructors
- Private attributes
- Constant references and const-correctness
- Prohibited copy construction and assignment

---

### 🔧 Requirements

You must implement a class `Warlock` with the following:

#### 🔒 Private Attributes

- `std::string name`
- `std::string title`

#### ✅ Public Member Functions

| Function | Description |
|---------|-------------|
| `Warlock(std::string const &, std::string const &)` | Constructor that sets name and title. |
| `~Warlock()` | Destructor — prints a farewell message. |
| `std::string const & getName() const` | Returns the Warlock's name. |
| `std::string const & getTitle() const` | Returns the Warlock's title. |
| `void setTitle(std::string const & title)` | Sets the Warlock's title. |
| `void introduce() const` | Displays the Warlock's introduction. |

#### ❌ Forbidden

- Default constructor
- Copy constructor
- Assignment operator

---

### 🧪 Example

```cpp
int main()
{
  Warlock const peter("Peter", "Mistress of Hell");
  peter.introduce();
  std::cout << peter.getName() << " - " << peter.getTitle() << std::endl;

  Warlock* john = new Warlock("John", "the Strong");
  john->introduce();
  john->setTitle("the Incredible");
  john->introduce();

  delete john;
  return 0;
}
```

#### ❌ Expected Output

	- Peter: This looks like another boring day.
	- Peter: I am Peter, Mistress of Hell!
	- Peter - Mistress of Hell
	- John: This looks like another boring day.
	- John: I am John, the Strong!
	- John: I am John, the Incredible!
	- John: My job here is done!
	- Peter: My job here is done!

---

### 🧠 Notes

- The Warlock must print a message when constructed and when destroyed.
- All messages must respect the format strictly, including punctuation.
- The introduce() method is meant to demonstrate basic class behavior.
- This is a foundational exercise to build upon in the next modules.

---

### ✅ Evaluation Checklist

- [x] Class follows Coplien form
- [x] Constructor and destructor print correct messages
- [x] Const correctness applied to getters
- [x] Copy operations are explicitly disabled
- [x] Output matches the example

---

| **➡️ Next exercise**               |
| --------------------------------- |
| [cpp_module_01](../cpp_module_01) |