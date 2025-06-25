## cpp_module_02 - Spellbook & Target Generator System

### 🚀 Objective

In this module, we introduce **factory patterns**, **non-copyable classes**, and **deferred object creation**. The `Warlock` now uses a `SpellBook` to manage his spells and a `TargetGenerator` to manage targets. This further modularizes and scales the spellcasting system.

---

### 📦 Files to submit

- `Warlock.hpp` / `Warlock.cpp`  
- `ASpell.hpp` / `ASpell.cpp`  
- `ATarget.hpp` / `ATarget.cpp`  
- `Fwoosh.hpp` / `Fwoosh.cpp`  
- `Fireball.hpp` / `Fireball.cpp`  
- `Polymorph.hpp` / `Polymorph.cpp`  
- `Dummy.hpp` / `Dummy.cpp`  
- `BrickWall.hpp` / `BrickWall.cpp`  
- `SpellBook.hpp` / `SpellBook.cpp`  
- `TargetGenerator.hpp` / `TargetGenerator.cpp`

---

### 📚 Concepts used

- Factory design pattern
- Deep copy and clone
- Object-oriented abstraction and encapsulation
- Static polymorphism (no RTTI/switches)
- Non-copyable classes (`SpellBook`, `TargetGenerator`)
- Reuse of existing components

---

### 🔧 Requirements

#### 🧙 Warlock Class (Updated)

- Now contains a `SpellBook` instance to manage known spells.
- Delegates spell learning, forgetting, and launching to the `SpellBook`.

#### 📖 SpellBook Class

A non-copyable class responsible for managing spell prototypes.

| Function | Description |
|----------|-------------|
| `void learnSpell(ASpell*)` | Clones and stores the spell |
| `void forgetSpell(std::string const & name)` | Forgets a spell if known |
| `ASpell* createSpell(std::string const & name)` | Returns a clone of the spell by name, or `nullptr` if not found |

#### 🏭 TargetGenerator Class

A non-copyable class responsible for managing target prototypes.

| Function | Description |
|----------|-------------|
| `void learnTargetType(ATarget*)` | Clones and stores the target type |
| `void forgetTargetType(std::string const & type)` | Forgets the target type if known |
| `ATarget* createTarget(std::string const & type)` | Returns a clone of the target by type, or `nullptr` if not found |

#### 🔮 Additional Spells (inherit from `ASpell`)

- `Fireball`: `"burnt to a crisp"`
- `Polymorph`: `"turned into a critter"`

#### 🧱 Additional Target (inherits from `ATarget`)

- `BrickWall`: `"Inconspicuous Red-brick Wall"`

---

### 🧪 Example

```cpp
int main()
{
  Warlock peter("Peter", "foo");
  peter.setTitle("Hello, I'm Peter the Warlock!");
  BrickWall model;

  Polymorph* polymorph = new Polymorph();
  TargetGenerator tarGen;

  tarGen.learnTargetType(&model);
  peter.learnSpell(polymorph);

  Fireball* fireball = new Fireball();

  peter.learnSpell(fireball);

  ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

  peter.introduce();
  peter.launchSpell("Polymorph", *wall);
  peter.launchSpell("Fireball", *wall);
}
```

#### Expected Output

	- Peter: This looks like another boring day.
	- Peter: I am Peter, Hello, I'm Peter the Warlock!!
	- Inconspicuous Red-brick Wall has been turned into a critter!
	- Inconspicuous Red-brick Wall has been burnt to a crisp!
	- Peter: My job here is done!

---

### 🧠 Notes

- No use of `switch` is allowed — use polymorphism and virtual dispatch.
- `SpellBook` and `TargetGenerator` must manage memory correctly (deep clones).
- Never return internal pointers directly without cloning.
- Avoid memory leaks — every `new` must have a corresponding delete, or use smart design to manage ownership.

---

### ✅ Evaluation Checklist

- [x] `SpellBook` and `TargetGenerator` are implemented and non-copyable
- [x] All spells and targets are clonable via `clone()`
- [x] Warlock can delegate correctly to factories
- [x] Memory is managed cleanly with deep copies
- [x] Output matches exactly
- [x] No forbidden constructs used (e.g., `switch`)

---

### 📁 Back to Previous Exercises

⬅️ [cpp_module_01](../cpp_module_01/README.md)
⬅️ [cpp_module_00](../cpp_module_00/README.md)