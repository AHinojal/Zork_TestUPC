#pragma once
class World {
	private:
		int edad;
	public:
		World(); // Constructor por defecto
		World(int edad); // Constructor base
		~World(); // Destructor

		int getEdad();
		void setEdad(int edad);
};
