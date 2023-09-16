from transformers import GPT2Model, GPT2Tokenizer

# Or "gpt2-medium", "gpt2-large", etc. depending on the size you want to use.
model_name = "gpt2"
tokenizer = GPT2Tokenizer.from_pretrained(model_name)
model = GPT2Model.from_pretrained(model_name)
 