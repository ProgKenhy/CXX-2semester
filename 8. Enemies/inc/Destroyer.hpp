#pragma once
#include <SpaceObject.hpp>

namespace ac
{
	class Destroyer : public SpaceObject
	{
	public:
		Destroyer() = default;
		virtual ~Destroyer() {}

		void Attack() override
		{
			std::cout << "Destroyer Attack" << std::endl;
		}

		void SpecialAbility() override
		{
			std::cout << "Destroyer Special Ability" << std::endl;
		}
	};
}