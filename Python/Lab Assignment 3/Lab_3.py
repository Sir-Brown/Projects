# D'Jaine Brown
# Lab Assignment 3
# 4/4/2026
# This program converts infix expressions to postfix and prefix notations, and evaluates them.

# Class to host functions for infix to postfix and prefix conversion, and evaluation
class ExpressionConverter:
    # Define operator precedence
    def __init__(self):
        self.precedence = {'+': 1, '-': 1, '*': 2, '/': 2}

    # Convert infix to postfix
    def infix_to_postfix(self, infix):
        output = []
        stack = []
        for token in infix.split():
            # If the token is a number, add to output
            if token.isdigit():
                output.append(token)
            
            # If the token is an operator, pop from stack to output until an operator with less precedence is found    
            elif token in self.precedence:
                while (stack and stack[-1] != '(' and self.precedence[stack[-1]] >= self.precedence[token]):
                    output.append(stack.pop())
                stack.append(token)

            # If the token is '(', push to stack    
            elif token == '(':
                stack.append(token)
            
            # If the token is ')', pop from stack to output until '(' is found
            elif token == ')':
                while stack and stack[-1] != '(':
                    output.append(stack.pop())
                
                # Pop '(' from stack
                stack.pop()

        # Pop any remaining operators from stack to output
        while stack:
            output.append(stack.pop())

        return ' '.join(output)
    
    # Convert infix to prefix
    def infix_to_prefix(self, infix):
        # Reverse the infix expression and swap parentheses
        rev_infix = infix.split()[::-1]
        for i in range(len(rev_infix)):
            if rev_infix[i] == '(':
                rev_infix[i] = ')'
            elif rev_infix[i] == ')':
                rev_infix[i] = '('

        # Convert to postfix
        postfix = self.infix_to_postfix(' '.join(rev_infix))

        # Reverse the postfix to get prefix
        prefix = postfix.split()[::-1]
        return ' '.join(prefix)
    
    # Evaluate postfix expression
    def evaluate_postfix(self, postfix):
        stack = []
        for token in postfix.split():
            # If token is a number, push to stack
            if token.isdigit():
                stack.append(float(token))
            else:
                # If token is an operator, pop two operands from stack
                right = stack.pop()
                left = stack.pop()
                if token == '+':
                    stack.append(left + right)
                elif token == '-':
                    stack.append(left - right)
                elif token == '*':
                    stack.append(left * right)
                elif token == '/':
                    stack.append(left // right)

        return stack[0]
    
    # Evaluate prefix expression
    def evaluate_prefix(self, prefix):
        stack = []
        for token in prefix.split()[::-1]:
            # If token is a number, push to stack
            if token.isdigit():
                stack.append(float(token))
            else:
                # If token is an operator, pop two operands from stack
                left = stack.pop()
                right = stack.pop()
                if token == '+':
                    stack.append(left + right)
                elif token == '-':
                    stack.append(left - right)
                elif token == '*':
                    stack.append(left * right)
                elif token == '/':
                    stack.append(left // right)

        return stack[0]

# Main
def main():
    converter = ExpressionConverter()

    # Get infix expression from user
    infix = input("Enter infix expression: ")
    
    # Convert infix to postfix and prefix
    postfix = converter.infix_to_postfix(infix)
    prefix = converter.infix_to_prefix(infix)
    
    # Display results
    print(f"Postfix: {postfix}")
    print(f"Prefix: {prefix}")
    
    # Evaluate postfix and prefix expressions
    postfix_eval = converter.evaluate_postfix(postfix)
    prefix_eval = converter.evaluate_prefix(prefix)
    
    # Display results
    print(f"Postfix Evaluation: {postfix_eval}")
    print(f"Prefix Evaluation: {prefix_eval}")

# Run main()
if __name__ == "__main__":
    main()