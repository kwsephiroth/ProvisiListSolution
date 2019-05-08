#ifndef MASTERINGREDIENTSLIST_H
#define MASTERINGREDIENTSLIST_H

#include "ingredientslist.h"
#include <unordered_map>

namespace ProvisiList
{
class MasterIngredientsList
{
private:
    using IngredientElement = std::pair<std::string, std::shared_ptr<Ingredient>>;
    std::unordered_map<std::string, std::shared_ptr<Ingredient>> m_ingredients;
    void Merge_Ingredients_List(IngredientsList&&);//Merges an IngredientsList into the master ingredients list
    void Merge_Ingredient(Ingredient);//Merges an Ingredient into the master ingredients list

public:
    MasterIngredientsList();
    void Add_Ingredients_List(IngredientsList&&);//Add a new ingredient list to merge into master list
    void Add_Ingredient(Ingredient ingredient);//Add a new ingredient to the list of ingredients
    void Remove_Ingredient(const std::string& ingredient_name);
    void Remove_All_Ingredients();
    size_t Get_Number_Of_Ingredients() const;
    std::shared_ptr<Ingredient> Get_Ingredient(const std::string& ingredient_name);//Returns a pointer to an ingredient in the list or nullptr if it doesn't exist
    const std::unordered_map<std::string, std::shared_ptr<Ingredient>>& Get_List() const;//Returns an immutable reference to the map of ingredients
};
}
#endif // MASTERINGREDIENTSLIST_H

