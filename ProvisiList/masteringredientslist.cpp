#include "masteringredientslist.h"
namespace ProvisiList
{
MasterIngredientsList::MasterIngredientsList()
{

}

void MasterIngredientsList::Add_Ingredients_List(IngredientsList && ingredients_list)
{
    auto list = ingredients_list.Get_List();

    for(auto itr = list.begin(); itr != list.end(); ++itr)
    {
        Add_Ingredient(*itr->second);
    }
}

void MasterIngredientsList::Add_Ingredient(Ingredient ingredient)
{
    auto ingredientName = ingredient.Get_Name();

    if(!ingredientName.empty())
    {
        auto ingredientPtr = m_ingredients.find(ingredientName);

        if(ingredientPtr != m_ingredients.end())//Existing ingredient detected, so must properly merge into master list
        {
            auto newQuantity = ingredient.Get_Quantity();
            auto newUnit = ingredient.Get_Unit_Of_Measurement();
            auto existingQuantity = ingredientPtr->second->Get_Quantity();
            auto existingUnit = ingredientPtr->second->Get_Unit_Of_Measurement();

            if(newUnit == existingUnit)
            {
                ingredientPtr->second->Set_Quantity((newQuantity + existingQuantity));
            }
            else//Units of measurement don't match, so they need to be normalized
            {

            }
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
