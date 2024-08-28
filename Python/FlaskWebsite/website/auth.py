from flask import Blueprint, render_template

auth = Blueprint('auth', __name__)

@auth.route('/login')
def login():
    pass

@auth.route('/sign_up')
def sign_up():
    pass

@auth.route('sign_out')
def sign_out():
    pass
