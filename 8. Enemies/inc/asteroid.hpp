#pragma once
#include <Enemies.hpp>

namespace ac
{
	class Asteroid : public Enemies
	{
	public:
		Asteroid() = default;
		virtual ~Asteroid() {}

		virtual void Attack() override
		{
			std::cout << "Asteroid Attack" << std::endl;
		}

		virtual void SpecialAbility() override
		{
			std::cout << "Asteroid Special Ability" << std::endl;
		}
	};
}