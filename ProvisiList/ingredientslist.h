#ifndef INGREDIENTSLIST_H
#define INGREDIENTSLIST_H
#include "ingredient.h"
#include <unordered_map>

namespace ProvisiList
{
class IngredientsList
{
private:
    std::unordered_map<std::string, std::shared_ptr<Ingredient>> m_ingredients;
    using IngredientElement = std::pair<std::string, std::shared_ptr<Ingredient>>;

protected:

public:
    IngredientsList();
    void Add_Ingredient(Ingredient ingredient);//Add a new ingredient to the list of ingredients
    void Remove_Ingredient(const std::string& ingredient_name);//Delete a specific ingredient from the list of ingredients using its name
    void Remove_All_Ingredients();//Clear the entire list of ingredients
    size_t Get_Number_Of_Ingredients() const;//Returns the number of ingredients currently in the list of ingredients
    std::shared_ptr<Ingredient> Get_Ingredient(const std::string& ingredient_name);//Returns a pointer to an ingredient in the list or nullptr if it doesn't exist
};
}
#endif // INGREDIENTSLIST_H

