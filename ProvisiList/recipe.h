#ifndef RECIPE_H
#define RECIPE_H
#include <string>
#include <unordered_map>
#include "ingredient.h"
#include "ingredientslist.h"
namespace ProvisiList
{
class Recipe
{
private:
    std::string m_name;//Recipe name
    std::shared_ptr<IngredientsList> m_ingredients_list;//List of ingredients
    std::string m_instructions;//Instructions for preparing the meal

protected:

public:
    Recipe(std::string name, IngredientsList&& ingredients_list, std::string instructions) :
        m_name(name),
        m_ingredients_list(std::make_shared<IngredientsList>(ingredients_list)),
        m_instructions(instructions)
    {}
    std::string Get_Name () const;
    std::shared_ptr<IngredientsList> Get_Ingredients_List() const;
    std::string Get_Instructions() const;
};
}
#endif // RECIPE_H
