// import { Select } from 'antd';
// source: https://www.youtube.com/watch?v=30J8Yv9eq7c&t=268s
module Select = {

    // [@bs.deriving]
    // type mode_t = 
    // | [@bs.as "multiple"] Multiple
    // | [@bs.as "default"] Default 
    // | [@bs.as "tags"] Tags;

    [@bs.module "Antd"]
    [@react.component]
    external make : (
        ~style: ReactDOMRe.Style.t=?, 
        ~className: string=?,
        ~allowClear: bool=?,
        ~autoClearSearchValue: bool=?,
        ~autoFocus: bool=?,
        ~defaultActiveFirstOption: bool=?,
        // ~defaultValue: string|string[]
        // int|int[]
        // LabeledValue|LabeledValue[]=?,
        ~disabled: bool=?,
        ~dropdownClassName: string=?,
        // ~dropdownMatchSelectWidth: bool | int=?,
        // ~dropdownRender: (menuNode: ReactNode=?, props) => ReactNode=?,
        //~dropdownStyle: CSSProperties=?,
        // ~filterOption: bool or function(inputValue=?, option)=?,
        // ~getPopupContainer: function(triggerNode)=?,
        ~labelInValue: bool=?,
        ~listHeight: int=?,
        ~maxTagCount: int=?,
        ~maxTagTextLength: int=?,
        // ~maxTagPlaceholder: ReactNode/function(omittedValues)=?,
        // ~tagRender: (props) => ReactNode=?,
        ~mode: string=?, //~mode: multiple | tags=?,
//        ~mode: mode_t=?,
        //~notFoundContent: ReactNode=?,
        ~optionFilterProp: string=?,
        ~optionLabelProp: string=?,
        // ~placeholder: string|ReactNode=?,
        ~showArrow: bool=?,
        ~showSearch: bool=?,
        // ~size: large | middle | small=?,
        // ~suffixIcon: ReactNode=?,
        // ~removeIcon: ReactNode=?,
        // ~clearIcon: ReactNode=?,
        // ~menuItemSelectedIcon: ReactNode=?,
        // ~tokenSeparators: string[]=?,
        // ~value: string|string[]
        // ?? int|int[]
        // ?? LabeledValue|LabeledValue[]=?,
        // ~virtual: bool=?,
        // ~onBlur: function=?,
        // ~onChange: function(value=?, option:Option/Array<Option>)=?,
        // ~onDeselect: function(string|int|LabeledValue)=?,
        ~onDeselect: (string => unit)=?,
        // ~onFocus: function=?,
        // ~onInputKeyDown: function=?,
        // ~onMouseEnter: function=?,
        // ~onMouseLeave: function=?,
        // ~onPopupScroll: function=?,
        // ~onSearch: function(value: string)=?,
        // ~onSelect: function(string|int|LabeledValue=?, option:Option)=?,
        ~onSelect: (string => unit)=?,
        ~defaultOpen: bool=?,
        // ~open: bool=?,
        // ~onDropdownVisibleChange: function(open)=?,
        ~loading: bool=?,
        ~bordered: bool=?,
        ~children: 'b


    ) => React.element = "Select";

    module Option = {
        [@bs.module "Antd"] [@bs.scope "Select"]
        [@react.component]
        external make : (
            ~style: ReactDOMRe.Style.t=?, 
            ~disabled: bool=?,
            ~title: string=?,
            //~value: string|number=?,
            ~className: string=?,
            ~children: 'd
        ) => React.element = "Option";
    };
};
