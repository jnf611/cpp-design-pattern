pipeline {
  agent any
  stages {
    stage('build') {
      steps {
        sh 'make'
      }
    }
    stage('test') {
      steps {
        sh 'make check'
      }
    }
  }
}