pipeline {
    agent {
        label 'pokemonsnap'
    }

    stages {
        stage('Setup') {
            steps {
                sh 'cp /usr/local/etc/roms/pokemonsnap.us.z64 pokemonsnap.z64'
                sh 'uv sync'
                sh 'cargo install pigment64'
                sh 'uv run ./configure.py --setup'
                sh 'uv run ./configure.py'
            }
        }
        stage('Build') {
            steps {
                sh "bash -o pipefail -c 'ninja 2>&1 | tee build_log.txt'"
            }
        }
        stage('Report Progress') {
            when {
                branch 'main'
            }
            steps {
                withCredentials([string(credentialsId: 'pokemonsnap_frogress', variable: 'frogress_key')]) {
                    sh 'uv run python3 tools/progress.py --frogress $frogress_key'
                }
            }
        }
    }
    post {
        always {
            cleanWs()
        }
    }
}
