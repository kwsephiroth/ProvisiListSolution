#include <iostream>
#include <UnitTest++/UnitTest++.h>
#include "../ProvisiList/ingredientslist.h"
#include "../ProvisiList/masteringredientslist.h"

using namespace ProvisiList;

SUITE(ProvisiList)
{
    TEST(CreateIngredientsList)
    {
        Ingredient i("Salt", 2.5, UnitOfMeasurement::Teaspoon);
        IngredientsList il;
        il.Add_Ingredient(i);

        auto ingredientPtr = il.Get_Ingredient("Salt");
        CHECK(ingredientPtr != nullptr);

        auto name = ingredientPtr->Get_Name();
        auto quantity = ingredientPtr->Get_Quantity();
        auto unit = ingredientPtr->Get_Unit_Of_Measurement();

        CHECK(name == "Salt");
        CHECK(quantity == 2.5);
        CHECK(unit == UnitOfMeasurement::Teaspoon);

        il.Remove_Ingredient("Salt");
        CHECK(il.Get_Number_Of_Ingredients() == 0);
    }

    TEST(CreateMasterIngredientsList_AddIngredient)
    {
        Ingredient i("Salt", 2.5, UnitOfMeasurement::Teaspoon);
        MasterIngredientsList il;
        il.Add_Ingredient(i);

        auto ingredientPtr = il.Get_Ingredient("Salt");
        CHECK(ingredientPtr != nullptr);

        auto name = ingredientPtr->Get_Name();
        auto quantity = ingredientPtr->Get_Quantity();
        auto unit = ingredientPtr->Get_Unit_Of_Measurement();

        CHECK(name == "Salt");
        CHECK(quantity == 2.5);
        CHECK(unit == UnitOfMeasurement::Teaspoon);

        Ingredient i2("Salt", 3, UnitOfMeasurement::Teaspoon);
        il.Add_Ingredient(i2);

        auto name2 = ingredientPtr->Get_Name();
        auto quantity2 = ingredientPtr->Get_Quantity();
        auto unit2 = ingredientPtr->Get_Unit_Of_Measurement();

        CHECK(name2 == "Salt");
        CHECK(quantity2 == 5.5);
        CHECK(unit2 == UnitOfMeasurement::Teaspoon);

        il.Remove_Ingredient("Salt");
        CHECK(il.Get_Number_Of_Ingredients() == 0);
    }
}

