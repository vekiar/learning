def evaluate(exp: Expression, env: Environment) -> Any:
	"Evaluate an expression in an environment"
	if isinstance(exp, Symbol):
		return env[exp]
	# ... lines omitted
	elif exp[0] == 'quote':
		(_, x) = exp
		return x
	elif exp[0] == 'if':
		(_, test, consequence, alternative) = exp
		if evaluate(test, env):
			return evaluate(consequence, env)
		else:
      return evaluate(alternative, env)
  elif exp[0] == 'lambda':
    (_, parms, *body) = exp
    return Procedure(parms, body, env)
  elif exp[0] == 'define':
    (_, name, value_exp) = exp
    env[name] = evaluate(value_exp, env)
  # ... more lines omitted
