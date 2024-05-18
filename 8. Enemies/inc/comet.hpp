#pragma once
#include <Enemies.hpp>

namespace ac
{
	class Comet : public Enemies
	{
	public:
		Comet() = default;
		virtual ~Comet() {}

		virtual void Attack() override
		{
			std::cout << "Comet Attack" << std::endl;
		}

		virtual void SpecialAbility() override
		{
			std::cout << "Comet Special Ability" << std::endl;
		}
	};
}