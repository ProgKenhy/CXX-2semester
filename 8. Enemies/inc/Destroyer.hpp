#pragma once
#include <SpaceObject.hpp>

namespace ac
{
	class Destroyer : public SpaceObject
	{
	public:
		Destroyer() = default;
		virtual ~Destroyer() {}

		void Attack()
		{
			std::cout << "Destroyer Attack" << std::endl;
		}

		void SpecialAbility()
		{
			std::cout << "Destroyer Special Ability" << std::endl;
		}
	};
}