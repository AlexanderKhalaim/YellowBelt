#include "node.h"
#include "date.h"

bool EmptyNode::Evaluate(const Date& date, const string& event) const {return true;}

DateComparisonNode::DateComparisonNode(Comparison cmp, const Date& date)
    : cmp_(cmp), date_(date) {}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
    if(cmp_ == Comparison::Less){
        return date < date_;
    }
    else if (cmp_ == Comparison::LessOrEqual){
        return date <= date_;
    }
    else if (cmp_ == Comparison::Greater){
        return date > date_;
    }
    else if (cmp_ == Comparison::GreaterOrEqual){
        return date >= date_;
    }else if (cmp_ == Comparison::Equal){
        return date == date_;
    }
    else if (cmp_ == Comparison::NotEqual){
        return date != date_;
    }
}

EventComparisonNode::EventComparisonNode(Comparison cmp, const string& event) : cmp_(cmp), event_(event) {}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
    if(cmp_ == Comparison::Less){
        return event < event_;
    }
    else if (cmp_ == Comparison::LessOrEqual){
        return event <= event_;
    }
    else if (cmp_ == Comparison::Greater){
        return event > event_;
    }
    else if (cmp_ == Comparison::GreaterOrEqual){
        return event >= event_;
    }else if (cmp_ == Comparison::Equal){
        return event == event_;
    }
    else if (cmp_ == Comparison::NotEqual){
        return event != event_;
    }
}

LogicalOperationNode::LogicalOperationNode(LogicalOperation op, shared_ptr<Node> left, shared_ptr<Node> right)
    : op_(op), left_(left), right_(right) {}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
    const bool left_result = left_->Evaluate(date, event);
    const bool right_result = right_->Evaluate(date, event);

    if (op_ == LogicalOperation::And) {
        return left_result && right_result;
    } else if (op_ == LogicalOperation::Or) {
        return left_result || right_result;
    }
}
