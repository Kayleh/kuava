# 安装GPT-2模型
from transformers import TextDataset, DataCollatorForLanguageModeling
from transformers import Trainer, TrainingArguments
import os
import glob
from transformers import GPT2Tokenizer, GPT2LMHeadModel
# 1. 加载模型
tokenizer = GPT2Tokenizer.from_pretrained('gpt2')
model = GPT2LMHeadModel.from_pretrained('gpt2')
# 2. 测试模型
text = "Replace me by any text you'd like."
num_samples =  5 # 返回的句子数量
#encoded_input = tokenizer(text, return_tensors='pt')
encoded_input = tokenizer(text, return_tensors='pt')
output = model(**encoded_input) 
# model.generate(**encoded_input, max_length=300, num_return_sequences=num_samples) 
#print(output)
# 3. 保存模型
model.save_pretrained('./gpt2-test')
tokenizer.save_pretrained('./gpt2-test')

# 在GPT2基础上嵌入微调
# 1. 加载数据集
""" files = glob.glob("data/*.txt")
print(files) """
current_directory = os.getcwd()
data_folder = os.path.join(current_directory, 'src/RUN/python3/data')
files = ""
for file_name in os.listdir(data_folder):
    if file_name.endswith('.txt'):
        # files.append(os.path.join(data_folder, file_name))
        files += ","+os.path.join(data_folder, file_name)
files = files[1:]
print(files)
#files = "/mnt/d/project/kayleh/kuava/src/RUN/python3/data/1.txt"
files = "data/1.txt"
# 2. 读取数据集


def load_dataset(files, tokenizer):
    dataset = TextDataset(
        tokenizer=tokenizer,
        file_path=files,
        block_size=128)
    return dataset


# 3. 数据集处理
def data_collator(data):
    data = torch.tensor(data)
    return data

# 4. 训练模型


def train_model():
    training_args = TrainingArguments(
        output_dir="./gpt2-test",
        overwrite_output_dir=True,
        num_train_epochs=1,
        per_device_train_batch_size=8,
        save_steps=10_000,
        save_total_limit=2
        # ,prediction_loss_only=True,
    )
    trainer = Trainer(
        model=model,
        args=training_args,
        data_collator=data_collator,
        train_dataset=load_dataset(files, tokenizer),
        # prediction_loss_only=True,
    )
    trainer.train(num_samples=10)
    trainer.save_model('./gpt2-test')


# 5. 测试模型
def test_model():
    from transformers import pipeline
    generator = pipeline('text-generation', model='./gpt2-test')
    print(generator("how much is the cook book?",
          max_length=30, num_return_sequences=5,num_samples=5))

# 6. 提问
def ask(s):
    from transformers import pipeline
    generator = pipeline('text-generation', model='./gpt2-test')
    print(generator(s,
          max_length=30, num_return_sequences=5 ,num_samples=5))

# 7. 运行
train_model()
test_model()
ask("how much is the cook book?")
#    