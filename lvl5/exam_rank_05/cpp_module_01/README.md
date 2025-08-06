## cpp_module_01 - Spellcasting System

### 🚀 Objective

This module expands on the previous Warlock exercise by introducing **abstract classes**, **inheritance**, **polymorphism**, and **dynamic memory management**. You will create a basic spellcasting system where a `Warlock` can learn, forget, and cast spells on various targets.

---

### 📦 Files to submit

- `Warlock.hpp` / `Warlock.cpp`  
- `ASpell.hpp` / `ASpell.cpp`  
- `ATarget.hpp` / `ATarget.cpp`  
- `Fwoosh.hpp` / `Fwoosh.cpp`  
- `Dummy.hpp` / `Dummy.cpp`

---

### 📚 Concepts used

- Inheritance and abstract base classes
- Virtual and pure virtual methods
- Dynamic polymorphism
- Managing memory with raw pointers
- Deep copies through `clone()` methods
- Encapsulation and interface design

---

### 🔧 Requirements

You must implement the following:

#### 🧙 Warlock Class

Enhance the previous version to include:

| Function | Description |
|---------|-------------|
| `void learnSpell(ASpell*)` | Learns a spell. Takes ownership (no copy required). |
| `void forgetSpell(std::string const & name)` | Forgets the spell with the given name. |
| `void launchSpell(std::string const & name, ATarget const & target)` | Launches the spell on a given target if known. |

- You must store known spells (using the container of your choice).
- Use spell names (strings) as unique identifiers.

#### 🔮 ASpell (Abstract)

| Member | Description |
|--------|-------------|
| `std::string name` | Spell name |
| `std::string effects` | Spell effect description |
| `virtual ASpell* clone() const = 0` | Must return a new heap-allocated copy of itself |
| `void launch(ATarget const &)` | Calls `getHitBySpell()` on the target |

#### 🎯 ATarget (Abstract)

| Member | Description |
|--------|-------------|
| `std::string type` | Type of the target |
| `virtual ATarget* clone() const = 0` | Must return a new heap-allocated copy of itself |
| `void getHitBySpell(ASpell const &)` | Displays: `<TYPE> has been <EFFECTS>!` |

#### 🔥 Fwoosh (Concrete Spell)

- Name: `"Fwoosh"`
- Effects: `"fwooshed"`

#### 🪵 Dummy (Concrete Target)

- Type: `"Target Practice Dummy"`

---

### 🧪 Example

```cpp
int main()
{
  Warlock peter("Peter", "the Lawyer");

  Dummy tommy;
  Fwoosh* fwoosh = new Fwoosh();

  peter.learnSpell(fwoosh);

  peter.introduce();
  peter.launchSpell("Fwoosh", tommy);

  peter.forgetSpell("Fwoosh");
  peter.launchSpell("Fwoosh", tommy);
}
```

#### Expected Output

	- Peter: This looks like another boring day.
	- Peter: I am Peter, the Lawyer!
	- Target Practice Dummy has been fwooshed!
	- Peter: My job here is done!

---

### 🧠 Notes

- `switch` statements are **forbidden** in all classes — use polymorphism.
- The Warlock must manage spell memory properly (avoid memory leaks).
- You must use deep copies when appropriate to avoid shared ownership issues.
- All output must follow the exact format specified.

---

### ✅ Evaluation Checklist

- [x] Abstract classes implemented correctly
- [x] Polymorphic clone methods working
- [x] Warlock can learn, forget, and cast spells
- [x] Output format is respected
- [x] No memory leaks or use-after-free
- [x] No usage of `switch` statements

---

| **⬅️ Previous exercise**              | **➡️ Next exercise**               |
| ------------------------------------ | --------------------------------- |
| [cpp_module_00](../cpp_module_00)    | [cpp_module_02](../cpp_module_02) |