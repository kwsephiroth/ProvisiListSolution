#include "ingredientslist.h"
namespace ProvisiList
{
IngredientsList::IngredientsList()
{

}

void IngredientsList::Add_Ingredient(Ingredient ingredient)
{
    auto ingredientName = ingredient.Get_Name();
    if(!ingredientName.empty())
    {
        m_ingredients.insert(IngredientElement(ingredientName, std::make_shared<Ingredient>(ingredient)));
    }
}

void IngredientsList::Remove_Ingredient(const std::string &ingredient_name)
{
    m_ingredients.erase(ingredient_name);
}

void IngredientsList::Remove_All_Ingredients()
{
    m_ingredients.clear();
}

size_t IngredientsList::Get_Number_Of_Ingredients() const
{
    return m_ingredients.size();
}

std::shared_ptr<Ingredient> IngredientsList::Get_Ingredient(const std::string &ingredient_name)
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

const std::unordered_map<std::string, std::shared_ptr<Ingredient>>& IngredientsList::Get_List() const
{
    return m_ingredients;
}

}
