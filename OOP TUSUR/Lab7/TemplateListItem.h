#pragma once
namespace Lab7
{
	template <class T>
	class TemplateListItem
	{
	public:
		TemplateListItem(T person)
		{
			Value = person;
		}
		TemplateListItem* Next = nullptr;
		TemplateListItem* Prev = nullptr;
		T Value; //Не сделал инкапсуляцию. Не перегружает оператор "<<"

		bool operator==(const TemplateListItem& right)
		{
			return Value == right.Value;
		}
	};
}