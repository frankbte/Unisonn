from django.shortcuts import render, HttpResponse

# Create your views here.

def index(request):
    return HttpResponse("Hello, world. You're at the myapp index.")

def detail(request, question_id):
    return HttpResponse("You are looking at question %s." % question_id)

def results(request, question_id):
    respone = "You are looking at the results of question %s."
    return HttpResponse(respone % question_id)

def vote(request, question_id):
    return HttpResponse("You are voting for question %s." % question_id)
