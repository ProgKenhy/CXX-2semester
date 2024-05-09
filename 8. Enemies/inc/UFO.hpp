#pragma once
#include <SpaceObject.hpp>

namespace ac
{
	class UFO : public SpaceObject
	{
	public:
		UFO() = default;
		virtual ~UFO() {}

		void Attack()
		{
			std::cout << "UFO Attack" << std::endl;
		}

		void SpecialAbility()
		{
			std::cout << "UFO Special Ability" << std::endl;
		}
	};
}