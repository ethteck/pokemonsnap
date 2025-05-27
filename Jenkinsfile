pipeline {
    agent {
        label 'pokemonsnap'
    }

    stages {
        stage('Setup') {
            steps {
                sh 'cp /usr/local/etc/roms/pokemonsnap.us.z64 pokemonsnap.z64'
                sh 'pip install -U -r requirements.txt --break-system-packages'
                sh 'cargo install pigment64'
                sh './configure.py --setup'
                sh './configure.py'
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
                sh 'python3 -m mapfile_parser objdiff_report report.json'
            }
        }
    }
    post {
        always {
            cleanWs()
        }
    }
}
