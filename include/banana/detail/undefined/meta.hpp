

template <>
struct reflector<api::undefined_type_t> {
    template <class F>
    static void for_each_field(F&& f) {
        
    }
};

template <> constexpr bool is_reflectable_v<api::undefined_type_t> = true;

template <> constexpr std::string_view name_of<api::undefined_type_t> = "undefined_type_t";


template <> struct reflector<api::business_intro_t>:public reflector<api::undefined_type_t>{};
template <> constexpr bool is_reflectable_v<api::business_intro_t> = true;
template <> constexpr std::string_view name_of<api::business_intro_t> = "business_intro_t";


template <> struct reflector<api::business_location_t>:public reflector<api::undefined_type_t>{};
template <> constexpr bool is_reflectable_v<api::business_location_t> = true;
template <> constexpr std::string_view name_of<api::business_location_t> = "business_location_t";


template <> struct reflector<api::business_opening_hours_t>:public reflector<api::undefined_type_t>{};
template <> constexpr bool is_reflectable_v<api::business_opening_hours_t> = true;
template <> constexpr std::string_view name_of<api::business_opening_hours_t> = "business_opening_hours_t";


template <> struct reflector<api::chat_location_t>:public reflector<api::undefined_type_t>{};
template <> constexpr bool is_reflectable_v<api::chat_location_t> = true;
template <> constexpr std::string_view name_of<api::chat_location_t> = "chat_location_t";

