## Design Paterns

## What is Design Pattern ? Explain its advantages ?

A design pattern systematically names, motivates, and explains a general design that addresses a recurring design problem in object-oriented systems. 

It describes the problem, the solution, when to apply the solution, and its consequences. It also gives implementation hints and examples. The solution is a general arrangement of objects and classes that solve the problem. The solution is customized and implemented to solve the problem in a particular context. 

## Different Types of Design Patterns ?

There are three basic classifications of patterns: 
	1. Creational 
	2. Structural
	3. Behavioral patterns.

### Creational Patterns

#### Abstract Factory: 
	Provide an interface for creating families of related or dependent objects without specifying their concrete classes
	Use the Abstract Factory pattern when
		* a system should be independent of how its products are created, composed, and represented.
		* a system should be configured with one of multiple families of products.
		* a family of related product objects is designed to be used together, and you need to enforce this constraint.
		* you want to provide a class library of products, and you want to reveal just their interfaces, not their implementations.

#### Builder
	Separate the construction of a complex object from its representation so that the same construction processes can create different representations.

	Builder VS Abstract factory
		- Builder focuses on contructing Complex object step by step. But abstract factory emphasis is on 
		families of product objects (Simple or complex)
		- Builder returns the product as final step, but Abstract factory the product is returned immediately


#### Factory Method
	Define an interface for creating an object, but let the subclasses decide which class to instantiate. Factory Method lets a class defer instantiation to subclasses.
	
#### Prototype
	A fully initialized instance to be copied or cloned 

#### Singleton
	A class in which only a single instance can exist 

### Structural Patterns

#### Adapter
	Match interfaces of different classes

#### Bridge
	Separates an object's abstraction from its implementation

#### Composite
	A tree structure of simple and composite objects

#### Decorator
	Add responsibilities to objects dynamically

#### Façade
	A single class that represents an entire subsystem

#### Flyweight
	A fine-grained instance used for efficient sharing

#### Proxy
	An object representing another object

### Behavioral Patterns

#### Mediator
	Defines simplified communication between classes

#### Memento
	Capture and restore an object's internal state 

#### Interpreter
	A way to include language elements in a program

#### Iterator
	Sequentially access the elements of a collection

#### Chain of Resp
	A way of passing a request between a chain of objects

#### Command
	Encapsulate a command request as an object

#### State
	Alter an object's behavior when its state changes

#### Strategy
	Encapsulates an algorithm inside a class

#### Observer
	A way of notifying change to a number of classes

#### Template Method
	Defer the exact steps of an algorithm to a subclass

#### Visitor
	Defines a new operation to a class without change

##  What is Builder design pattern in Java ? When do you use Builder pattern in Java ?

##  What is Singleton pattern in Java ?

##  What is decorator pattern in Java ? Can you give an example of Decorator pattern ?

Attach additional responsibilities to an object DYNAMICALLY.

##  What is Factory pattern in Java? What is advantage of using static factory method to create object ?

A factory method pattern is a creational pattern. It is used to instantiate an object from one among a set of classes based on a logic.

##  What is Observer design pattern in Java ? When do you use Observer pattern in Java ?

##  Can you write thread-safe Singleton in Java ?


# References

#### Online Reading with code examples

  https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns
  https://sourcemaking.com/design_patterns

#### Online Videos

##### Examples with Code

	https://www.youtube.com/watch?v=j9arNRRoPe8

##### 2 Hours detailed talk
	
	https://www.youtube.com/watch?v=ALxQdnOdYXQ

# Working Examples
	
Chain of Responsibilites
	IPCService -> ONVIF IPC Service
	BaseCGI -> SystemCGI

Abstract Factory:
	