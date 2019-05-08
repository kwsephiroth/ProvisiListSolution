#include <iostream>
#include <UnitTest++/UnitTest++.h>
#include "../ProvisiList/ingredientslist.h"

using namespace ProvisiList;

SUITE(ProvisiList)
{
    TEST(AddIngredients)
    {
        Ingredient i("Salt", 2.5, UnitOfMeasurement::Teaspoon);
        IngredientsList il;
        il.Add_Ingredient(i);
        auto saltPtr = il.Get_Ingredient("Salt");
        std::cout << saltPtr->Get_Quantity() << std::endl;
    }

    TEST(RemoveIngredients)
    {
        std::cout << "RemoveIngredients test invoked!" << std::endl;
    }
}

