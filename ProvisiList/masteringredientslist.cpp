#include "masteringredientslist.h"
namespace ProvisiList
{
void MasterIngredientsList::Merge_Ingredients_List(IngredientsList &&)
{

}

void MasterIngredientsList::Merge_Ingredient(Ingredient)
{

}

MasterIngredientsList::MasterIngredientsList()
{

}

void MasterIngredientsList::Add_Ingredients_List(IngredientsList &&)
{

}

void MasterIngredientsList::Add_Ingredient(Ingredient ingredient)
{
    auto ingredientName = ingredient.Get_Name();

    if(!ingredientName.empty())
    {
        auto ingredientPtr = m_ingredients.find(ingredientName);

        if(ingredientPtr != m_ingredients.end())//Existing ingredient detected, so must properly merge into master list
        {
           Merge_Ingredient(ingredient);
        }
        else//New ingredient detected, so simply add to master list
        {
           m_ingredients.insert(IngredientElement(ingredientName, std::make_shared<Ingredient>(ingredient)));
        }
    }
}

void MasterIngredientsList::Remove_Ingredient(const std::string &ingredient_name)
{
    m_ingredients.erase(ingredient_name);
}

void MasterIngredientsList::Remove_All_Ingredients()
{
    m_ingredients.clear();
}

size_t MasterIngredientsList::Get_Number_Of_Ingredients() const
{
    return m_ingredients.size();
}

std::shared_ptr<Ingredient> MasterIngredientsList::Get_Ingredient(const std::string &ingredient_name)
{
    auto ingredientPtr = m_ingredients.find(ingredient_name);

    if(ingredientPtr != m_ingredients.end())
    {
        return ingredientPtr->second;
    }
    else
    {
        return nullptr;
    }
}

const std::unordered_map<std::string, std::shared_ptr<Ingredient> > &MasterIngredientsList::Get_List() const
{
    return m_ingredients;
}
}
