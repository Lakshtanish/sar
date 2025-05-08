from sentence_transformers import SentenceTransformer, util
import torch
import streamlit as st

# Load the BERT model
@st.cache_resource
def load_model():
    return SentenceTransformer('paraphrase-MiniLM-L6-v2')

model = load_model()

# Customer Service FAQ Knowledge Base (No Emojis)
faq_pairs = {
    "Hi": "Hello! How can I assist you today?",
    "Hello": "Hi there! What can I help you with?",
    "Goodbye": "Goodbye! Have a fantastic day!",
    "Thank you": "You're most welcome!",
    "What is your name?": "I'm Ava, your friendly customer assistant bot.",
    "Do you offer refunds?": "Yes, we offer hassle-free refunds within 30 days of purchase.",
    "How do I return a product?": "You can initiate a return through your account's 'Orders' section.",
    "How can I track my order?": "You can track your order using the link emailed to you after purchase.",
    "Can I cancel my order?": "Absolutely! Just ensure it's within 24 hours of ordering.",
    "Tell me about the product": "Could you please specify which product you're referring to?",
    "What is the price of the product?": "Please share the product name so I can check the price for you.",
    "Is there any warranty on the product?": "Yes, all our products come with a 1-year standard warranty.",
    "Do you ship internationally?": "Yes! We proudly deliver to most countries across the globe.",
    "What payment methods do you accept?": "We accept Credit/Debit cards, UPI, PayPal, and Net Banking.",
    "I forgot my password": "No worries! Click on 'Forgot Password' on the login page to reset it.",
    "Can I change my shipping address?": "Yes, you can update your shipping address within 12 hours of placing your order.",
    "CEO": "Which company's CEO would you like to know about?",
    "Apple": "Apple's current CEO is Tim Cook.",
    "Tesla": "Elon Musk is the CEO of Tesla.",
    "What is my name?": "You are Yashraj, a student at PICT, Pune."
}

# Encode FAQ questions
questions = list(faq_pairs.keys())
question_embeddings = model.encode(questions, convert_to_tensor=True)

# Response generator using semantic similarity
def get_response(user_input):
    user_embedding = model.encode(user_input, convert_to_tensor=True)
    cosine_scores = util.pytorch_cos_sim(user_embedding, question_embeddings)
    top_result = torch.argmax(cosine_scores)

    if cosine_scores[0][top_result] > 0.6:
        return faq_pairs[questions[top_result]]
    else:
        return "I'm sorry, I didn't understand that. Could you please rephrase or ask something else?"

# Chat UI using Streamlit
st.set_page_config(page_title="Customer Support Assistant", page_icon="💬")
st.title("Ava - Your Virtual Customer Support Assistant")

# Session state for chat history
if "messages" not in st.session_state:
    st.session_state.messages = []

# Display chat history
for msg in st.session_state.messages:
    with st.chat_message(msg["role"]):
        st.markdown(msg["content"])

# User input
user_input = st.chat_input("Type your question here...")

if user_input:
    # Append user message
    st.session_state.messages.append({"role": "user", "content": user_input})
    with st.chat_message("user"):
        st.markdown(user_input)

    # Get assistant response
    response = get_response(user_input)
    st.session_state.messages.append({"role": "assistant", "content": response})
    with st.chat_message("assistant"):
        st.markdown(response)
